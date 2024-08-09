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
    vector<vector<int>>ans;
    void sol(TreeNode* root, int targetSum, vector<int>temp){
        if(!root) return;

        if(!root->left && !root->right){
            if(targetSum == root->val){
                temp.push_back(root->val);
                ans.push_back(temp);
            }

            return;
        }
        temp.push_back(root->val);
        targetSum = targetSum - root->val;
        sol(root->left, targetSum, temp);
        sol(root->right, targetSum, temp);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return {};
        vector<int>temp;
        sol(root, targetSum, temp);
        return ans;
    }
};