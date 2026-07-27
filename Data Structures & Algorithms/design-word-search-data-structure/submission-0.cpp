struct TrieNode {
    TrieNode *children[26];
    bool isEnd = false;
};

class WordDictionary {
private: 
    TrieNode *root;
    
    bool backtrack(TrieNode *root, int start, const string& word) {
        if (!root) return false;

        if (start == word.length()) {
            return root->isEnd;
        }

        char c = word[start];
        if (c != '.') {
            int ind = c - 'a';
            return backtrack(root->children[ind], start + 1, word);
        } else {
            for (int i = 0; i < 26; i++) {
                if (backtrack(root->children[i], start + 1, word)) return true;
            }
            return false;
        }
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
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
    
    bool search(string word) {
        return (backtrack(root, 0, word));
    }
};
