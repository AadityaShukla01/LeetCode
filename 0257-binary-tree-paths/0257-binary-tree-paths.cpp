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
    void sol(TreeNode *root,string ans,vector<string> &res){
    if(root==NULL) {
        return ;
    }

    //leaf node
    if(root->left == NULL && root->right == NULL){
        ans+=to_string(root->val);
        res.push_back(ans);
        return ;
    }

    ans+=to_string(root->val)+"->";

    sol(root->left,ans,res);
    sol(root->right,ans,res);
 }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string res="";
        sol(root,res,ans);

        return ans;
    }
};