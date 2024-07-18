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
    bool isLeaf(TreeNode* root){
        if(!root) return false;
        if(root->left == NULL && root->right == NULL)
            return true;
        return false;
    }
    map<TreeNode*, TreeNode*>mp;
    void findPar(TreeNode* root){
        if(!root) return;   
        if(root->left){
            mp[root->left] = root;
        }
        if(root->right){
            mp[root->right] = root;
        }
        if(root->left)
            findPar(root->left);
        if(root->right)    
            findPar(root->right);
    }
    int count;
    int distance;
    set<TreeNode*>set;
    void sol(TreeNode* root, int len, map<TreeNode*, int>&v){
        if(!root) return;
        if(len > distance) return;
        if(isLeaf(root) && len >= 1 && len <= distance && set.find(root) == set.end()) {
            if(v.find(root) != v.end()) return;
            v[root]++;
            // cout << root->val << "\n";
            count++;
            return;
        }

        sol(root->left, len + 1, v);
        sol(root->right, len + 1, v);

        TreeNode* par = mp[root];
        if(par)
            sol(par, len + 1, v);
    }
    void dfs(TreeNode* root){
        if(!root) return;

        dfs(root->left);
        dfs(root->right);
        if(isLeaf(root)){
            set.insert(root);
            map<TreeNode*, int>v;
            sol(root, 0, v);
        }
    }
    int countPairs(TreeNode* root, int distance) {
        this->distance = distance;
        findPar(root);
        dfs(root);
        return count;
    }
};