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
class FindElements {
public:
    map<int, int>mp;
    void calc(TreeNode* root, int val){
        if(!root) return;

        root->val = val;

        mp[val]++;       

        if(root->left) calc(root->left, 2*val + 1);
        if(root->right) calc(root->right, 2*val + 2);
    }
    FindElements(TreeNode* root) {
        mp.clear();
        calc(root, 0);
    }
    
    bool find(int target) {
        if(mp.find(target) != mp.end())
            return true;
        return false;      
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */