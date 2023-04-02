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
    bool sol(TreeNode*root,int k,TreeNode *node){
        if(root==NULL) return false;
        if(root->val==k && root!=node) 
            return true;
        else if(root->val < k) 
            return sol(root->right,k,node);
        else 
            return sol(root->left,k,node);

        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        queue<TreeNode*>q;
        q.push(root);

        while(q.empty()==false){
            int n=q.size();//no of node in a level
            for(int i=0;i<n;i++){
                TreeNode *node=q.front();
                int a=node->val;
                q.pop();
               
                if(sol(root,k-a,node)) return true;
                
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
        }
        return false;
    }
};