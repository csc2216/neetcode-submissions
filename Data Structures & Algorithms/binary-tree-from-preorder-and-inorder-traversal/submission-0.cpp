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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();

        unordered_map<int, int> inorder_index;  // <val, index>
        for (int i = 0; i < n; i++) {
            inorder_index[inorder[i]] = i;
        }

        stack<pair<TreeNode*, int>> st;

        int root_val = preorder[0];
        TreeNode *root = new TreeNode(root_val);
        st.push({root, inorder_index[root_val]});

        TreeNode *top, *prev_top, *curr;
        int top_order, prev_top_order, curr_order, curr_val;
        for (int i = 1; i < n; i++) {
            curr_val = preorder[i];
            curr_order = inorder_index[curr_val];
            curr = new TreeNode(curr_val);
            
            top = st.top().first;
            top_order = st.top().second;

            if (curr_order < top_order) {
                top->left = curr;
                st.push({curr, curr_order});

            } else {
                while (curr_order > top_order) {
                    prev_top = top;  prev_top_order = top_order;
                    st.pop();
                    if (!st.empty()) {
                        top = st.top().first;
                        top_order = st.top().second;    
                    } else break;
                }
                prev_top->right = curr;
                st.push({curr, curr_order});
            }
        }

        return root;    
    }
};
