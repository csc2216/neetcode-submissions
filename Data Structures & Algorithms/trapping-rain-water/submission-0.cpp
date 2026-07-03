class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int result = 0;
        vector<int> lmax(n), rmax(n);

        lmax[0] = height[0];
        rmax[n - 1] = height[n - 1];
        for (int i = 1; i < n - 1; i++) {
            lmax[i] = max(lmax[i -1], height[i]);
            rmax[n - 1 - i] = max(rmax[n - i], height[n - 1 - i]);
        }

        for (int i = 1; i < n - 1; i++) {
            int trap = max(min(lmax[i - 1], rmax[i + 1]) - height[i], 0);
            result += trap;
        } 
        return result;


        


        
    }
};
