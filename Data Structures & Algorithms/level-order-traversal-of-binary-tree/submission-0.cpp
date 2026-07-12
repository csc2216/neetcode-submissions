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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> wait;

        if (!root) return result; 
        wait.push(root);

        int level = 0, level_size;
        TreeNode *now; 
        while (!wait.empty()) {
            level_size = wait.size();
            vector<int> num_list;
            for (int i = 0; i < level_size; i++) {
                now = wait.front();
                num_list.push_back(now->val);
                if (now->left) wait.push(now->left);
                if (now->right) wait.push(now->right);
                wait.pop();
            }
            result.push_back(num_list);
            level++;
        }

        return result;
    }
};
