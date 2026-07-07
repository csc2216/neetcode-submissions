class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int m = 1;
        for (int i = 0; i < n; i++) {
            m = max(m, piles[i]);
        }

        int l = 1;
        int r = m;
        int mid = l + (r - l) / 2;
        int k;
        while (l <= r) {
            long t = 0;
            for (int i = 0; i < n; i++) {
                t += (piles[i] + mid - 1) / mid;
            }
            if (t <= h) {
                k = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
            mid = l + (r - l) / 2;
        }
        return k;
    }
};
