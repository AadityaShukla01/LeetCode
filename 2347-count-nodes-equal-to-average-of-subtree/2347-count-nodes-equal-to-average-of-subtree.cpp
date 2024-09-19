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
    int count;
    pair<int, int> sol(TreeNode* root)
    {
        if(!root) return {0, 0};

        pair<int, int>l = sol(root->left);
        pair<int, int>r = sol(root->right);

        if(root->val == (l.first + r.first + root->val)/(l.second + r.second + 1))
            count++;

        return {l.first + r.first + root->val, l.second + r.second + 1};
    }
    int averageOfSubtree(TreeNode* root) {
        sol(root);
        return count;
    }
};