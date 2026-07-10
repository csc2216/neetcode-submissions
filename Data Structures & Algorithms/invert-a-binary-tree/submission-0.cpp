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
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> wait_to_invert;
        if (root != nullptr) wait_to_invert.push(root);
        while (!wait_to_invert.empty()) {
            TreeNode *node = wait_to_invert.front();
            swap(node->left, node->right);
            if(node->left != nullptr) wait_to_invert.push(node->left);
            if(node->right != nullptr) wait_to_invert.push(node->right);
            wait_to_invert.pop();
        }
        return root;
    }
};
