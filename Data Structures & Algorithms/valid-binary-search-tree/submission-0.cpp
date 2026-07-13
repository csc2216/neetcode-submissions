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
    bool isValidBST(TreeNode* root) {
        minmax(root);
        return isValid;
    }

private:
    bool isValid = true;
    pair<int, int> minmax(TreeNode *node) {
        int min, max;
        if (!isValid) return {0, 0};

        if (node->left) {
            if (minmax(node->left).second >= node->val) isValid = false;
            else min = minmax(node->left).first;
        } else min = node->val;

        if (node->right) {
            if (minmax(node->right).first <= node->val) isValid = false;
            else max = minmax(node->right).second;
        } else max = node->val;

        return {min, max};
    }
};
