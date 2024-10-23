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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        while(q.empty() == false)
        {
            int sz = q.size();
            int sum  = 0;
            vector<TreeNode*>ans;
            for(int i=0; i<sz; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                ans.push_back(node);
                if(node->left)
                {
                    sum += node->left->val;
                    q.push(node->left);
                } 
                if(node->right) 
                {
                    sum += node->right->val;
                    q.push(node->right);
                }
            }

            for(int i=0; i<ans.size(); i++)
            {
                int temp = sum;

                if(ans[i]->left)
                    temp -= ans[i]->left->val;

                if(ans[i]->right)
                    temp -= ans[i]->right->val;

                if(ans[i]->left) ans[i]->left->val = temp;
                if(ans[i]->right) ans[i]->right->val = temp;
            }
        }
        root->val = 0;
        return root;
    }
};