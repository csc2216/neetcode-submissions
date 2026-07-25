class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        int max_count = 0;
        for (char t : tasks) {
            count[t - 'A']++;
            max_count = max(max_count, count[t - 'A']);
        }

        int max_count_num = 0;
        for (int i = 0; i < 26; i++) {
            if (count[i] == max_count) {
                max_count_num++;
            }
        }

        int lower_bound = (max_count - 1) * (n + 1) + max_count_num;

        return max(lower_bound, (int)tasks.size());
    }
};
