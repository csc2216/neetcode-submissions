class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        auto nums_begin = nums.begin();
        auto nums_end = nums.end();
        int longest_length = 0;

        for (int num : nums) {
            if (find(nums_begin, nums_end, num - 1) == nums_end) {
                int count = 1;
                int plus1 = num + 1;
                while (find(nums_begin, nums_end, plus1) != nums_end) {
                    count++;
                    plus1++;
                }
                if (count > longest_length) longest_length = count;
            }
        }
        return longest_length;
    }
};
