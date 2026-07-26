class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        vector<int> path;
        vector<vector<int>> res;
        backtrack(nums, 0, used, path, res);
        return res;
    }

private:
    void backtrack(const vector<int>& nums,
                   int start,
                   vector<bool>& used,
                   vector<int>& path,
                   vector<vector<int>>& res)
    {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            path.push_back(nums[i]);
            used[i] = true;

            backtrack(nums, i + 1, used, path, res);

            path.pop_back();
            used[i] = false;
        }
    }
};
