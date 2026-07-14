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
    int maxPathSum(TreeNode* root) {
        max_chain_sum(root);
        return max_sum;
    }

private: 
    int max_sum = INT_MIN;

    int max_chain_sum(TreeNode *node) {
        if (!node) return 0;
        int left_sum = max_chain_sum(node->left);
        int right_sum = max_chain_sum(node->right);
        int as_top = node->val + max(left_sum, 0) + max(right_sum, 0);
        max_sum = max(max_sum, as_top);
        return node->val + max(max(left_sum, right_sum), 0);
    }
};
