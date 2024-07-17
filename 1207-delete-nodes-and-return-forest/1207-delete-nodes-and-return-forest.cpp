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
    TreeNode* sol(TreeNode* root, map<int, int>&mp, vector<TreeNode*>&ans){
        if(!root) return NULL;

        // POSTORDER 
        root->left = sol(root->left, mp, ans);
        root->right = sol(root->right, mp,ans);

        if(mp.find(root->val) != mp.end()){
            if(root->left) ans.push_back(root->left);
            if(root->right) ans.push_back(root->right);

            return NULL;
        }


        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        map<int, int>mp;
        for(auto val: to_delete) mp[val]++;
        vector<TreeNode*>ans;
        sol(root, mp, ans);
        if(mp.find(root->val) == mp.end()){
            ans.push_back(root);
        }
        return ans;
    }
};