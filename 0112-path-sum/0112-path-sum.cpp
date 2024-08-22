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
    bool sol(TreeNode* root, int targetSum){
        if(!root) return false;

        if(!root->left && !root->right){
            return targetSum == root->val;
        }
        
        targetSum -= root->val;


        bool l = sol(root->left, targetSum);
        bool r = sol(root->right, targetSum);


        return l || r;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return sol(root, targetSum);
    }
};