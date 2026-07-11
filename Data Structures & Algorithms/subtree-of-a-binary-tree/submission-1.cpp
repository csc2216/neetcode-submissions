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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        subtree_depth = get_depth(subRoot);
        check_and_get_depth(root, subRoot);
        return found;
    }

private:
    int subtree_depth;
    bool found = false;

    int get_depth(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(get_depth(root->left), get_depth(root->right));
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p & !q) return true;
        if (!p || !q) return false;
        return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right) && p->val == q->val);
    }

    int check_and_get_depth(TreeNode *node, TreeNode *subRoot) {
        if (!node || found) return 0;

        int depth = 1 + max(check_and_get_depth(node->left, subRoot), check_and_get_depth(node->right, subRoot));
        if (depth == subtree_depth) {
            if (isSameTree(node, subRoot)) found = true;
        }

        return depth;
    }
};

