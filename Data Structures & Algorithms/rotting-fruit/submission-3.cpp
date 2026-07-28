class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(); 
        int n = grid[0].size();
        queue<pair<int, int>> q;

        bool hasOne = false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                if (!hasOne && grid[i][j] == 1) {
                    hasOne = true;
                }
            }
        }
        if (q.empty()) {
            if (hasOne) return -1;
            else return 0;
        }

        int time = -1;
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!q.empty()) {
            int num = q.size();
            for (int k = 0; k < num; k++) {
                auto [i, j] = q.front();
                q.pop();

                for (auto& d : dirs) {
                    int r = i + d[0];
                    int c = j + d[1];

                    if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1) {
                        grid[r][c] = 2;
                        q.push({r, c});
                    }
                }
            }
            time++;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) return -1;
            }
        }
        return time;
    }
};
