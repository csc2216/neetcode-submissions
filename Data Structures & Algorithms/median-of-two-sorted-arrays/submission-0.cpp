class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> sort;
        int n1 = nums1.size();
        int n2 = nums2.size();
        int stop = (n1 + n2) / 2 + 1;
        bool is_odd = (n1 + n2) % 2 == 1;

        int i1 = 0, i2 = 0; 
        while (sort.size() < stop) {
            if (i1 != n1 && (i2 == n2 || nums1[i1] <= nums2[i2])) {
                sort.push_back(nums1[i1]);
                i1++;
            } else {
                sort.push_back(nums2[i2]);
                i2++; 
            }
        }

        if (is_odd) return (float)sort[stop - 1];
        else return (float)(sort[stop - 2] + sort[stop - 1]) / 2.0;
    }
};
