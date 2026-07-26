class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int sum = 0;
        vector<int> comb;
        vector<vector<int>> res;

        backtrack(candidates, 0, sum, target, comb, res);
        return res;
    }

private:
    
    void backtrack(const vector<int>& nums, 
                   int start,
                   int sum,
                   const int& target,
                   vector<int>& comb,
                   vector<vector<int>>& res)
    {
        if (sum == target) {
            res.push_back(comb);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) continue;
            
            if (sum + nums[i] > target) break; 

            comb.push_back(nums[i]);
            backtrack(nums, i + 1, sum + nums[i], target, comb, res); 
            comb.pop_back();
        }
    }
};
