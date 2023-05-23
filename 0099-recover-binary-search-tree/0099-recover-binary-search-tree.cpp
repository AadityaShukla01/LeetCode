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
    TreeNode *node1=NULL;
    TreeNode *node2=NULL;
    TreeNode *pre= new TreeNode(INT_MIN);
    void sol(TreeNode *root){
        if(root==NULL)
            return;
        sol(root->left);
        //inorder traversal of bst gives sortted values of tree
        if(node1 == NULL && root->val < pre->val)
            node1=pre;
        if(node1 != NULL && root->val < pre->val)
            node2=root;
        pre=root;
        sol(root->right);
    }
    void recoverTree(TreeNode* root) {
        sol(root);
        if(node1 && node2)
            swap(node1->val,node2->val);
    }
};