struct TrieNode {
    TrieNode *children[26];
    bool isEnd = false;
};

class PrefixTree {
private: 
    TrieNode *root;
    
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
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
        TrieNode *node = root;
        for (char c : word) {
            int ind = c - 'a';
            if (!node->children[ind]) return false;
            node = node->children[ind];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode *node = root;
        for (char c : prefix) {
            int ind = c - 'a';
            if (!node->children[ind]) return false;
            node = node->children[ind];
        }
        return true;
    }
};
