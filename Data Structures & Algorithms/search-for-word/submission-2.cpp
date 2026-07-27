class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (backtrack(board, 0, i, j, word)) return true;
            }
        }
        return false;
    }

private:
    bool backtrack(vector<vector<char>>& board, int wordInd, int i, int j, const string& word) {
        if (wordInd == word.size()) {
            return true;
        }

        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[wordInd]) {
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '#';

        bool found = backtrack(board, wordInd + 1, i - 1, j, word) ||
                     backtrack(board, wordInd + 1, i + 1, j, word) ||
                     backtrack(board, wordInd + 1, i, j - 1, word) ||
                     backtrack(board, wordInd + 1, i, j + 1, word);

        board[i][j] = temp;
        return found;
    }
};
