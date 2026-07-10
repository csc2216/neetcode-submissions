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
        int max_depth = 0, depth = 0;
        stack<pair<TreeNode* , int>> chain;
        if (root != nullptr) {
            chain.push({root, 1});
            depth++;
            max_depth = 1;
        }
        int side, find_new;
        while (!chain.empty()) {
            TreeNode *top_node = chain.top().first;
            if (top_node->left != nullptr) {
                chain.push({top_node->left, 0});
                depth++;
                max_depth = max(max_depth, depth);
            } else if (top_node->right != nullptr) {
                chain.push({top_node->right, 1});
                depth++;
                max_depth = max(max_depth, depth);
            } else {
                find_new = 0;
                do {
                    side = chain.top().second;
                    chain.pop();
                    depth--;
                    if (side == 0) {
                        TreeNode *right_node = chain.top().first->right;
                        if (right_node != nullptr) {
                            chain.push({right_node, 1});
                            depth++;
                            find_new = 1;
                        }
                    }
                } while (find_new == 0 && !chain.empty());
            }
        }
        return max_depth;
    }
};
