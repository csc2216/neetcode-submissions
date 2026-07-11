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
    bool isBalanced(TreeNode* root) {
        bool balanced = true;
        depth(root, balanced);
        return balanced;
    }

private:
    int depth(TreeNode *node, bool& balanced) {
        if (node == nullptr) return 0;

        int left_depth = depth(node->left, balanced);
        int right_depth = depth(node->right, balanced);
        if (abs(left_depth - right_depth) > 1) {
            balanced = false;
        }

        return max(left_depth, right_depth) + 1;
    }
};
