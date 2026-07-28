class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size(); 
        int n = grid[0].size();
        queue<pair<int, int>> cells;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    cells.push({i, j});
                }
            }
        }

        int dist = 1;
        while (!cells.empty()) {
            int num = cells.size();
            for (int k = 0; k < num; k++) {
                auto [i, j] = cells.front();
                cells.pop();

                if (i > 0 && dist < grid[i-1][j]) {
                    grid[i-1][j] = dist;
                    cells.push({i - 1, j});
                }
                if (i < m - 1 && dist < grid[i+1][j]) {
                    grid[i+1][j] = dist;
                    cells.push({i + 1, j});
                }
                if (j > 0 && dist < grid[i][j-1]) {
                    grid[i][j-1] = dist;
                    cells.push({i, j - 1});
                }
                if (j < n - 1 && dist < grid[i][j+1]) {
                    grid[i][j+1] = dist;
                    cells.push({i, j + 1});
                }
            }
            dist++;
        }
    }
};
