class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;

        for (int i = 0; i < nums.size(); i++) {
            int find_num = target - nums[i];

            if (seen.find(find_num) != seen.end()) {
                return {seen[find_num], i};
            }

            seen[nums[i]] = i;
        }

    }
};
