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
    unordered_map<int,int>map;
    int sum=0;
    void inorder(TreeNode *root){
        if(root==NULL)
            return ;
        inorder(root->left);
        map[root->val]=sum;
        sum = sum + root->val;
        inorder(root->right);
    }
    void sol(TreeNode *root){
        if(root==NULL)
            return ;
        sol(root->left);
        root->val=sum-map[root->val];
        sol(root->right);
    }
    TreeNode* bstToGst(TreeNode* root) {
        inorder(root);
        sol(root);
        return root;
    }
};