struct TrieNode {
    TrieNode *children[26];
    bool isEnd = false;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        for (string word : words) {
            addWord(word);
        }

        unordered_set<string> found;
        vector<string> res;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                backtrack(root, i, j, "", board, found, res);
            }
        }
        
        return res;
    }

private:
    TrieNode *root;

    void addWord(string word) {
        TrieNode *node = root;
        for (char c : word) {
            int ind = c - 'a';
            if (!node->children[ind]) {
                node->children[ind] = new TrieNode();
            }
            node = node->children[ind];
        }
        node->isEnd = true;
    }

    void backtrack(TrieNode *root,
                   int i, int j,
                   string s,
                   vector<vector<char>>& board,
                   unordered_set<string>& found,
                   vector<string>& res) 
    {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == '#') return;

        int ind = board[i][j] - 'a';
        TrieNode *node = root->children[ind];
        if (!node) return;
        s.push_back(board[i][j]);
        
        if (node->isEnd && !found.contains(s)) {
            found.insert(s);
            res.push_back(s);
        }

        char temp = board[i][j];
        board[i][j] = '#';

        backtrack(node, i - 1, j, s, board, found, res);
        backtrack(node, i + 1, j, s, board, found, res);
        backtrack(node, i, j - 1, s, board, found, res);
        backtrack(node, i, j + 1, s, board, found, res);

        board[i][j] = temp;
    }
};
