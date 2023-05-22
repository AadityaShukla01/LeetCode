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

    TreeNode *sol(TreeNode *root,int target){
        if(root==NULL)
            return NULL;
            
        root->left=sol(root->left,target);
        root->right=sol(root->right,target);
        if(root->left==NULL && root->right==NULL && root->val==target)
            return NULL;
        else 
            return root;
            
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return sol(root,target);
    }
};