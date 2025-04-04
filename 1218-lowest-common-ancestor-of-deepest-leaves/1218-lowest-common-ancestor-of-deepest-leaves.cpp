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
    map<TreeNode*, int>heights;
    int calcHeight(TreeNode* root)
    {
        if(!root) return 0;

        int l = calcHeight(root->left);
        int r = calcHeight(root->right);

        heights[root] = max(l, r) + 1;
        return heights[root];
    } 
    TreeNode* sol(TreeNode* root)
    {
        if(!root) return NULL;

        int l = heights[root->left];
        int r = heights[root->right];

        if(l > r) return sol(root->left);
        else if(r > l) return sol(root->right);
        else return root;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        calcHeight(root);
        return sol(root);
    }
};