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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool find = false;
        int big = max(p->val, q->val);
        int small = min(p->val, q->val);
        TreeNode *node = root;
        int now;
        while (find == false) {
            now = node->val;
            if (now < small) node = node->right;
            else if (now > big) node = node->left;
            else return node;
        }   
    }
};
