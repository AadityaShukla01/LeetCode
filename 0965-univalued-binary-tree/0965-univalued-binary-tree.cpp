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
        unordered_set<int>set;
    bool sol(TreeNode*root,int &x){
        if(root){
            cout<<x<<endl;
            if(root->val!=x) 
                return false;
            if(sol(root->left,x)==false) return false;
            if(sol(root->right,x)==false) return false;
        }
        return true;
    }
    
    bool isUnivalTree(TreeNode* root) {
        int x=root->val;
        cout<<x<<endl;
        return sol(root,x);

    }
};