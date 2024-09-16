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
    bool sol(TreeNode*left, TreeNode*ryt)
    {
        if(!left && !ryt) return true;
        if(!left || !ryt) return false;
        if(left->val != ryt->val) return false;

        bool l = sol(left->left, ryt->right);
        bool r = sol(left->right, ryt->left);

        return l && r;
    }
    bool isSymmetric(TreeNode* root) {
        return sol(root->left, root->right);
    }
};