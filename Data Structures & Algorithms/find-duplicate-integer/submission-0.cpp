class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int swap_i, swap;
        for (int i = 0; i < nums.size() - 1; i++) {
            while (nums[i] != i + 1) {
                swap_i = nums[i] - 1;
                swap = nums[swap_i];
                if (swap_i < i || nums[i] == nums[swap_i]) return nums[i];
                nums[swap_i] = nums[i];
                nums[i] = swap;
            }
        }
        return nums[nums.size() - 1];   
    }
};
