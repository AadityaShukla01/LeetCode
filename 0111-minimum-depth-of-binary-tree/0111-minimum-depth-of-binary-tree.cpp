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
    int minDepth(TreeNode* root) {
        int ans=0;
        vector<vector<int>>om;
           //base case
            if(root==NULL)
            return 0;


         queue<TreeNode*>q;
         q.push(root);

         TreeNode*temp;
         int sze=0;

         while(q.empty()==false){
             sze=q.size();
             for(int i=0;i<sze;i++){

                 temp=q.front();
                 q.pop();
                if(!temp->left && !temp->right)
                return ans+1;
                 if(temp->left)
                     q.push(temp->left);
                     
                 if(temp->right)
                     q.push(temp->right);
             }
             ans++;
         }
        return 1;
    }
};