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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val > key){
            root->left = deleteNode(root->left,key);
        }
        else if(root->val < key){
            root->right = deleteNode(root->right,key);
        } //if we found element to be deleted
        else{ //iff leaf node
            if(root->left ==NULL && root->right==NULL){
                return NULL;
            } //no leaf but only one child
            if(root->left==NULL ||  root->right==NULL){
                if(root->left){
                    return root->left;
                }
                else{
                    return root->right;
                }
            }

            else{ //lowest predecsor
                TreeNode*ans=root->left;
                while(ans->right)
                ans=ans->right;
                root->val=ans->val;
                root->left=deleteNode(root->left,ans->val);
            }
        }
        return root;
    }
};