class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int result = 0;
        int l = 0, r = n - 1;

        while (l < r) {
            int cur_amount = min(heights[l], heights[r]) * (r - l);
            if (cur_amount > result) result = cur_amount;

            if (heights[l] > heights[r]) {
                r--;
            } else l++;  
        }
        return result;
    }
};
