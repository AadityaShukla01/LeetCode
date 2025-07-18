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
    int maxSum;
    int sol(TreeNode* root) {
        if (!root)
            return 0;

        int l = max(0, sol(root->left));
        int r = max(0, sol(root->right));

        maxSum = max({maxSum, l + r + root->val});

        return max(l, r) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return root->val;
        maxSum = -1e9;
        sol(root);
        return maxSum;
    }
};