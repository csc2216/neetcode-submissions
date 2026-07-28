class Solution {
public:
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; i++) {
            track(board, i, 0);
            track(board, i, n - 1);
        }
        for (int j = 1; j < n - 1; j++) {
            track(board, 0, j);
            track(board, m - 1, j);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                switch(board[i][j]) {
                    case '#':
                        board[i][j] = 'O';
                        break;
                    case 'O':
                        board[i][j] = 'X';
                        break;
                }
            }
        }
        
    }

private:
    int m;
    int n;
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void track(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O') return;

        board[i][j] = '#';
      
        for (auto& d : dirs) {
            int r = i + d[0];
            int c = j + d[1];
            track(board, r, c);
        }
    }
};
