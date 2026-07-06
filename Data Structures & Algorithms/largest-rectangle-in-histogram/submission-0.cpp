class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> lb(n, -1), rb(n, n);
        stack<pair<int, int>> stl, str;  /* <index, height> */
        int result = 0;

        for (int i = 0; i < n; i++) {
            while (!stl.empty() && heights[i] < stl.top().second) {
                rb[stl.top().first] = i;
                stl.pop();
            }
            stl.push({i, heights[i]});

            int j = n - 1 - i;
            while (!str.empty() && heights[j] < str.top().second) {
                lb[str.top().first] = j;
                str.pop();
            }
            str.push({j, heights[j]});
        }

        for (int i = 0; i < n; i++) {
            result = max(result, heights[i] * (rb[i] - lb[i] - 1));
        }
        return result;
    }
};
