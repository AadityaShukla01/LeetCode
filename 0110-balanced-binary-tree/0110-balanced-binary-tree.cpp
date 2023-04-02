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
    int sol(TreeNode*root){
        if(root==NULL)
        return 0;

        return 1+max(sol(root->left),sol(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
        return true;

        int left=sol(root->left);
        int right=sol(root->right);

        bool left1=isBalanced(root->left);
        bool right1=isBalanced(root->right);

        if(abs(left-right)>1)
        return false;

        return left1 && right1;
    }
};