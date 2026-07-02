class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre_prod(n - 1), suf_prod(n - 1), result(n);
        pre_prod[0] = nums[0];
        suf_prod[0] = nums[n - 1];
        for (int i = 1; i < n - 1; i++) {
            pre_prod[i] = pre_prod[i - 1] * nums[i];
            suf_prod[i] = suf_prod[i - 1] * nums[n - 1 - i];
        }
        result[0] = suf_prod[n - 2];
        result[n - 1] = pre_prod[n - 2];
        for (int i = 1; i < n - 1; i++) {
            result[i] =  pre_prod[i - 1] * suf_prod[n - 2 - i];
        }

        return result;

    }
};
