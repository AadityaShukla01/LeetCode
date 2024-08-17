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
    int ans;
    void sol(TreeNode* root, int mn, int mx){
        if(!root) return;
        if(mn != INT_MAX && mx != INT_MAX)
            ans = max({ans, abs(root->val - mn), abs(root->val - mx)});

        mn = min(mn, root->val);
        mx = max(mx, root->val);

        sol(root->left, mn, mx);
        sol(root->right, mn, mx);
    }
    int maxAncestorDiff(TreeNode* root) {
        sol(root, INT_MAX, INT_MIN);
        return ans;
    }
};