class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i : {0, 1, 2}) {
            for (int j : {0, 1, 2}) {
                unordered_set<char> row, col, box;
                int k = 3 * i + j;

                for (int l = 0; l < 9; l++) {
                    char row_num = board[k][l];
                    char col_num = board[l][k];
                    char box_num = board[3*i + l/3][3*j + l%3];

                    if (row_num != '.') {
                        if (row.find(row_num) != row.end()) {
                            return false;
                        }
                        row.insert(row_num);
                    }
                    if (col_num != '.') {
                        if (col.find(col_num) != col.end()) {
                            return false;
                        }
                        col.insert(col_num);
                    }
                    if (box_num != '.') {
                        if (box.find(box_num) != box.end()) {
                            return false;
                        }
                        box.insert(box_num);
                    }
                }
            }
        }
        return true;
    }
};
