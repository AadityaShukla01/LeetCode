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
//in such straight forward questions always use itertaive inorder traversals its time complexity is lesser
    int ans=INT_MAX;
    int c=0;
    void sol(TreeNode*root,int k){
        if(root==NULL)
        return ;
        sol(root->left,k);
        c++;
        if(c==k){
            ans=root->val;
        }
        sol(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        sol(root,k);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};