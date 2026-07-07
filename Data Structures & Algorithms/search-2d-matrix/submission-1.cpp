class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int l = 0;
        int r = m * n - 1;
        int mid = (l + r) / 2;
        int i = mid / n;
        int j = mid % n;

        while (l <= r) {
            if (target == matrix[i][j]) return true;
            if (target > matrix[i][j]) l = mid + 1;
            if (target < matrix[i][j]) r = mid - 1;
            mid = (l + r) / 2;
            i = mid / n;
            j = mid % n;
        }
        return false;
    }
};
