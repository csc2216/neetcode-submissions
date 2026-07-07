class Solution {
public:
    int findMin(vector<int> &nums) {
        int a = nums[0];
        int l = 0;
        int r = nums.size() - 1;
        int mid;
        int ans = a;

        while (l <= r) {
            mid = l + (r - l) / 2;
            if (nums[mid] >= a) {
                l = mid + 1;
            } else {
                ans = nums[mid];
                r = mid - 1;
            }
        }
        return ans;
    }
};
