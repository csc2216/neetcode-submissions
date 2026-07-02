class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set(nums.begin(), nums.end());
        auto end = num_set.end();
        int longest_length = 0;

        for (int num : nums) {
            if (num_set.find(num - 1) == end) {
                int count = 1;
                int plus1 = num + 1;
                while (num_set.find(plus1) != end) {
                    count++;
                    plus1++;
                }
                if (count > longest_length) longest_length = count;
            }
        }
        return longest_length;
    }
};
