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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> q;

        if (!root) return result; 
        q.push(root);

        int level_size;
        TreeNode *now; 
        while (!q.empty()) {
            level_size = q.size();
            for (int i = 0; i < level_size; i++) {
                now = q.front();
                if (now->left) q.push(now->left);
                if (now->right) q.push(now->right);
                if (i == level_size - 1) result.push_back(now->val);
                q.pop();
            }
        }

        return result;
    }
};
