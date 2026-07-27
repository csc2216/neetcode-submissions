class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        for (int i = 0; i < n; i++) {
            string s = "";
            for (int j = 0; j < n; j++) {
                s.push_back('.');
            }
            board.push_back(s);
        }

        vector<int> placed(n);
        vector<vector<string>> res;
        backtrack(0, n, placed, res);
        return res;
    }

private:
    vector<string> board;

    void backtrack(int start, int n, vector<int>& placed, vector<vector<string>>& res) {
        if (start == n) {
            vector<string> sol = board;
            for (int i = 0; i < n; i++) {
                sol[i][placed[i]] = 'Q';
            }
            res.push_back(sol);
            return;
        }

        vector<bool> avai(n, true);
        for (int i = 0; i < start; i++) {
            avai[placed[i]] = false;
            if (placed[i] - start + i >= 0) avai[placed[i] - start + i] = false;
            if (placed[i] + start - i < n)  avai[placed[i] + start - i] = false;   
        }

        for (int i = 0; i < n; i++) {
            if (avai[i]) {
                placed[start] = i;
                backtrack(start + 1, n, placed, res);
            }
        }
    }
};
