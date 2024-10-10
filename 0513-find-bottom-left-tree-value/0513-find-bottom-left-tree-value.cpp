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
    unordered_map<int, int>mp;
    void sol(TreeNode* root, int l)
    {
        if(!root) return;
        ans = max(ans, l);
        if(mp.find(l) == mp.end()) mp[l] = root->val;

        sol(root->left, l + 1);
        sol(root->right, l + 1);
    }
    int findBottomLeftValue(TreeNode* root) {
        ans = -1;
        mp.clear();
        sol(root, 0);
        return mp[ans];
    }
};