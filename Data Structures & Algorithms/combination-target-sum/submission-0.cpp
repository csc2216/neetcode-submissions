class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int sum = 0;
        vector<int> comb;
        vector<vector<int>> res;
        backtrack(nums, 0, sum, target, comb, res);
        return res;
    }

private:

    void backtrack(const vector<int>& nums, 
                   int start, 
                   int& sum,
                   const int& target,
                   vector<int>& comb, 
                   vector<vector<int>>& res)
    {
        for (int i = start; i < nums.size(); i++) {
            sum += nums[i];
            comb.push_back(nums[i]);

            if (sum < target) {
                backtrack(nums, i, sum, target, comb, res);
            } else if (sum == target) {
                res.push_back(comb);
            } 

            sum -= nums[i];
            comb.pop_back();
        }
    }
};
