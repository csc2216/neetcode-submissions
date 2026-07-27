struct TrieNode {
    TrieNode *children[26]{};
    string word;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        for (string word : words) {
            addWord(word);
        }

        vector<string> res;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                backtrack(root, i, j, board, res);
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
        node->word = word;
    }

    void backtrack(TrieNode *root,
                   int i, int j,
                   vector<vector<char>>& board,
                   vector<string>& res) 
    {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == '#') return;

        char c = board[i][j];
        int ind = c - 'a';
        TrieNode *node = root->children[ind];
        if (!node) return;
        
        if (!node->word.empty()) {
            res.push_back(node->word);
            node->word = "";
        }

        board[i][j] = '#';

        backtrack(node, i - 1, j, board, res);
        backtrack(node, i + 1, j, board, res);
        backtrack(node, i, j - 1, board, res);
        backtrack(node, i, j + 1, board, res);

        board[i][j] = c;
    }
};

