
// all in one
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> preOrder;
        vector<int> inOrder;
        vector<int> postOrder;
        if (!root) return postOrder;
        stack<pair<TreeNode*,int>> st;
        st.push({root, 1});
        while (st.size() > 0) {
            auto [curr, state] = st.top();
            if (state == 1) {
                preOrder.push_back(curr->val);
                st.top().second = 2;
                if (curr->left) st.push({curr->left, 1});
            }
            else if (state == 2) {
                inOrder.push_back(curr->val);
                st.top().second = 3;
                if (curr->right) st.push({curr->right, 1});
            }
            else {
                postOrder.push_back(curr->val);
                st.pop();
            }
        }
        return postOrder;
    }
};