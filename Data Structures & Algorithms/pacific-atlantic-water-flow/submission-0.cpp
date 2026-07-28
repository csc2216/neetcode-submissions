class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        
        vector<vector<bool>> pac(m, vector<bool>(n, false)), 
                             atl(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            pac[i][0] = true;
            atl[i][n-1] = true;
        }
        for  (int j = 0; j < n; j++) {
            pac[0][j] = true;
            atl[m-1][j] = true;
        }

        for (int i = 0; i < m; i++) {
            track(heights, i, 0, pac);
            track(heights, i, n - 1, atl);
        }
        for (int j = 0; j < n; j++) {
            track(heights, 0, j, pac);
            track(heights, m - 1, j, atl);
        }

        vector<vector<int>> res;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pac[i][j] && atl[i][j]) {
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }

private:
    int m;
    int n;
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    void track(const vector<vector<int>>& heights, int i, int j, vector<vector<bool>>& sea) {
        int val = heights[i][j];
        for (auto& d : dirs) {
            int r = i + d[0];
            int c = j + d[1];

            if (r >= 0 && r < m && c >= 0 && c < n && !sea[r][c] && heights[r][c] >= val) {
                sea[r][c] = true;
                track(heights, r, c, sea);
            }
        }
            
    }
};
