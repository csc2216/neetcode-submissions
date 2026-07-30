class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);  // <target, time>
        for (const auto& t : times) {
            adj[t[0]].push_back({t[1], t[2]});
        }

        // <time, node>
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        vector<int> dist(n + 1, 1e9);
        
        dist[k] = 0;
        minHeap.push({0, k});

        while (!minHeap.empty()) {
            auto [time, u] = minHeap.top();
            minHeap.pop();

            if (time > dist[u]) continue;

            for (const auto& [v, weight] : adj[u]) {
                int vtime = time + weight;
                if (vtime < dist[v]) {
                    dist[v] = vtime;
                    minHeap.push({vtime, v});
                }
            }
        }

        int maxDelay = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == 1e9) return -1;
            maxDelay = max(maxDelay, dist[i]);
        }
        return maxDelay;
    }
};
