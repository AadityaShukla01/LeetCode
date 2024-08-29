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
    bool sol(TreeNode* root){
        if(!root) return true;

        bool l = sol(root->left);
        bool r = sol(root->right);
        
        if(root->val == 2){
            bool ans = l | r;
            return ans;
        }
        else if(root->val == 3){
            bool ans = l & r;
            return ans;
        }
        else{
            return root->val;
        }
    }
    bool evaluateTree(TreeNode* root) {
        return sol(root);
    }
};