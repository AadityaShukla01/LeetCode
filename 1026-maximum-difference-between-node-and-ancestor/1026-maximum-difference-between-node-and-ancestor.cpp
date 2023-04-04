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
    int maxAncestorDiff(TreeNode* root) {
        if(root==NULL) return 0;

        return sol(root,INT_MAX,INT_MIN);
    }
    int sol(TreeNode *root,int mini,int maxi){
        //find the max/min value in that path
        if(root==NULL) return maxi-mini;
        
        maxi=max(maxi,root->val);
        mini=min(mini,root->val);

        int left=sol(root->left,mini,maxi);
        int right=sol(root->right,mini,maxi);

        return max(left,right);
    }
};