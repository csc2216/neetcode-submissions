class Twitter {
private:
    struct Tweet {
        int id;
        int time;
        Tweet(int id, int time) : id(id), time(time) {}
    };
    
    struct HeapNode {
        int time;
        int tweetId;
        int userId;
        int ind;  // index in user's vec<tweet>
        HeapNode(int time, int tweetId, int userId, int ind) : 
            time(time), tweetId(tweetId), userId(userId), ind(ind) {}

        bool operator<(const HeapNode& other) const {
            return time < other.time; // Max-Heap
        }
    };

    int globalTime;
    unordered_map<int, vector<Tweet>> userTweets;
    unordered_map<int, unordered_set<int>> followMap;

public:
    Twitter() : globalTime(0) {}
    
    void postTweet(int userId, int tweetId) {
        userTweets[userId].push_back({tweetId, globalTime++});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> news;

        unordered_set<int> userSet = followMap[userId];
        userSet.insert(userId);

        priority_queue<HeapNode> heap;
        for (int user : userSet) {
            const auto& tweets = userTweets[user];
            if (!tweets.empty()) {
                int lastInd = tweets.size() - 1;
                heap.push({tweets[lastInd].time, 
                           tweets[lastInd].id,
                           user,
                           lastInd});
            }
        }
        while (!heap.empty() && news.size() < 10) {
            HeapNode node = heap.top();
            heap.pop();

            news.push_back(node.tweetId);

            int ind = node.ind - 1;
            if (ind >= 0) {
                int user = node.userId;
                Tweet tweet = userTweets[user][ind];
                heap.push({tweet.time, tweet.id, user, ind});
            }
        }

        return news;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};
