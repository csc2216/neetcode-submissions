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

class Solution {
public:
    int maxDepth(TreeNode* root) {
        int max_depth = 0;
        stack<pair<TreeNode*, int>> st;
        if (root != nullptr) st.push({root, 1});
        
        while (!st.empty()) {
            auto [node, depth] = st.top();
            st.pop();
            max_depth = max(max_depth, depth);

            if (node->right) st.push({node->right, depth + 1});
            if (node->left) st.push({node->left, depth + 1});
        }
        
        return max_depth;
    }
};
