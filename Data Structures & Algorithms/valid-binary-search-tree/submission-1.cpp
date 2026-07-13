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
        int min = INT_MIN, max = INT_MAX;
        isValid(root, min, max);
        return valid;
    }

private:
    bool valid = true;
    void isValid(TreeNode *node, int min, int max) {
        if (!valid) return;
        if (node->val <= min || node->val >= max) {
            valid = false;
            return;
        }
        if (node->left) isValid(node->left, min, node->val);
        if (node->right) isValid(node->right, node->val, max);
    }
};
