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
    bool isCompleteTree(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*>q;
        q.push(root);
        stack<TreeNode*>st;
        while(q.empty() == false){
            int sz = q.size();
            bool flag = false;
            for(int i=0; i<sz; i++){
                TreeNode* node = q.front();
                q.pop();

                if(st.empty() == false && node->left && !st.top()) return false;
                st.push(node->left);
                if(node->left)
                    q.push(node->left);
                if(node->right && !st.top()) return false;
                if(node->right)
                    q.push(node->right);
                st.push(node->right);
            }
        }
        return true;
    }
};