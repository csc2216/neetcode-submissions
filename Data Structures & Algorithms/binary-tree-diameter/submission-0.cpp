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
    int diameterOfBinaryTree(TreeNode* root) {
        int max_diameter = 0;
        depth(root, max_diameter);
        return max_diameter;
    }

private:
    int depth(TreeNode *node, int& max_diameter) {
        if (node == nullptr) return 0;

        int left_depth = depth(node->left, max_diameter);
        int right_depth = depth(node->right, max_diameter);
        if (left_depth + right_depth > max_diameter) {
            max_diameter = left_depth + right_depth;
        }

        return max(left_depth, right_depth) + 1;
    }
};
