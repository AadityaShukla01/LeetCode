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
    int res;
    vector<int>sol(TreeNode* root)
    {
        if(!root) return {INT_MAX, INT_MIN, 0};

        vector<int>l = sol(root->left);
        vector<int>r = sol(root->right);

        if(root->val > l[1] && root->val < r[0])
        {
            int sum = l[2] + r[2] + root->val;
            
            res = max(res, sum);

            int mn = min(l[0], root->val);
            int mx = max(r[1], root->val);

            return {mn, mx, sum};
        }
        return {INT_MIN, INT_MAX, max(l[2], r[2])};
    }
    int maxSumBST(TreeNode* root) {
        if(!root) return 0;
        res = 0;
        return max(res, sol(root)[2]);
    }
};