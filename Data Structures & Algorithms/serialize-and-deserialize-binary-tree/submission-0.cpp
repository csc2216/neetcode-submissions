/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        addNode_preorder(root, res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data[0] == 'n') return nullptr;

        stack<TreeNode*> st;
        stringstream ss(data);

        string s;
        getline(ss, s, ',');
        TreeNode *root = new TreeNode(stoi(s));
        st.push(root);
        
        TreeNode *prev = root, *curr;
        while (true) {
            while (getline(ss, s, ',') && s != "n") {
                curr = new TreeNode(stoi(s));
                st.push(curr);
                prev->left = curr;
                prev = curr;
            }

            while (getline(ss, s, ',') && s == "n") {
                st.pop();
            }
            if (st.empty()) return root;
            else {
                prev = st.top();
                st.pop();
                curr = new TreeNode(stoi(s));
                st.push(curr);
                prev->right = curr;
                prev = curr;
            }
        } 
    }

private:

    void addNode_preorder(TreeNode *root, string& res) {
        if (!root) {
            res += "n,";
            return;
        }
        res += to_string(root->val) + ",";
        addNode_preorder(root->left, res);
        addNode_preorder(root->right, res);
    }
};
