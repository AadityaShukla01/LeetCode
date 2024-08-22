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
    map<int, int>mp;
    TreeNode* sol(int &postEnd, int inStart, int inEnd, vector<int>&postorder){
        if(inStart > inEnd) return NULL;

        int val = postorder[postEnd];
        int index = mp[val];

        TreeNode* root = new TreeNode(val);

        postEnd--;

        root->right = sol(postEnd, index + 1, inEnd, postorder);
        root->left = sol(postEnd, inStart, index - 1, postorder);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();

        for(int i=0; i<n; i++) mp[inorder[i]] = i;
        int postEnd = n - 1;
        return sol(postEnd, 0, n - 1, postorder);
    }
};