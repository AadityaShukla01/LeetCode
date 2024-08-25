/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        sol(root, ans);
        return ans;
    }
    void sol(TreeNode* root, vector<int>& nums) {
        if (root == NULL)
            return;

        sol(root->left, nums);
        sol(root->right, nums);
        nums.push_back(root->val);
    }
};