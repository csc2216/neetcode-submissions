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
    int goodNodes(TreeNode* root) {
        int good_num = 0;
        good(root, INT_MIN, good_num);
        return good_num;
    }

private:
    void good(TreeNode *node, int prev_max, int& good_num) {
        if (!node) return;
        if (node->val >= prev_max) {
            good_num++;
            int curr_max = node->val;
            good(node->left, curr_max, good_num);
            good(node->right, curr_max, good_num);
        } else {
            good(node->left, prev_max, good_num);
            good(node->right, prev_max, good_num);
        }
    }
};
