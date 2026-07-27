class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        
        vector<bool> cols(n, false);
        vector<bool> diag1(2 * n, false);  // r - c + n
        vector<bool> diag2(2 * n, false);  // r + c

        backtrack(0, n, board, cols, diag1, diag2, res);
        return res;
    }

private:
    void backtrack(int r, int n, vector<string>& board,
                   vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2,
                   vector<vector<string>>& res) {
        if (r == n) {
            res.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {
            if (cols[c] || diag1[r - c + n] || diag2[r + c]) continue;

            board[r][c] = 'Q';
            cols[c] = diag1[r - c + n] = diag2[r + c] = true;

            backtrack(r + 1, n, board, cols, diag1, diag2, res);

            board[r][c] = '.';
            cols[c] = diag1[r - c + n] = diag2[r + c] = false;
        }
    }
};
