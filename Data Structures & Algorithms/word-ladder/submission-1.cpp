class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());

        if (!words.contains(endWord)) return 0;

        queue<string> q;
        q.push(beginWord);

        int dist = 1;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                string word = q.front();
                q.pop();

                for (int j = 0; j < word.length(); j++) {
                    char originalChar = word[j];

                    for (char c = 'a'; c <= 'z'; c++) {
                        word[j] = c;

                        if (word == endWord) return dist + 1;

                        if (words.contains(word)) {
                            q.push(word);
                            words.erase(word);
                        }
                    }

                    word[j] = originalChar;
                }
            }
            dist++;
        }

        return 0;
    }
};
