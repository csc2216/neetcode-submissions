class Solution {
public:
    int search(vector<int>& nums, int target) {
        int a = nums[0];
        bool comp = target >= a;
        int l = 0;
        int r = nums.size() - 1;
        int mid;

        while (l <= r) {
            mid = l + (r - l) / 2;
            if (nums[mid] >= a) {
                if (comp) {
                    if (nums[mid] == target) return mid;
                    else if (nums[mid] > target) r = mid - 1;
                    else if (nums[mid] < target) l = mid + 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (comp) {
                    r = mid - 1;
                } else {
                    if (nums[mid] == target) return mid;
                    else if (nums[mid] > target) r = mid - 1;
                    else if (nums[mid] < target) l = mid + 1;
                }
            }
        }

        return -1;
    }
};
