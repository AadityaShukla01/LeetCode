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
    TreeNode* reverseOddLevels(TreeNode* root) {
        int level = -1;
        queue<TreeNode*>q;

        q.push(root);
        vector<TreeNode*>pre;
        pre.push_back(root);
        while(q.empty() == false)
        {
            int sz = q.size();
            level++;
            vector<TreeNode*>temp(sz);
            for(int i=0; i<sz; i++)
            {
                TreeNode* node = q.front();
                q.pop();

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

                temp[i] = node;
            }
            // for(auto it: temp) cout << it->val << " ";
            // cout << "\n";
            if(level % 2 == 0)
            {
                pre = temp;
                continue;
            }
            int j = sz - 1;
            for(int i=0; i<pre.size(); i++)
            {
                TreeNode* par = pre[i];
                TreeNode* leftN = temp[j--];
                TreeNode* rytN = temp[j--];


                par->left = leftN;
                par->right = rytN;
            }
            for(int i=0; i<sz/2; i++)
            {
                
                if(temp[sz - i - 1]->left) swap(temp[sz - i - 1]->left, temp[i]->left);
                if(temp[sz - i - 1]->right) swap(temp[sz - i - 1]->right, temp[i]->right);    
            }
        }
        return root;
    }
};