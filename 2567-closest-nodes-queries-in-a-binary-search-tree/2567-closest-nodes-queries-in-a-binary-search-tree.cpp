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
    vector<int>a;
    void sol(TreeNode* root)
    {
        if(!root) return ;
        sol(root->left);
        a.push_back(root->val);
        sol(root->right);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        sol(root);
        int n = a.size();
        vector<vector<int>>ans;
        for(auto q: queries){
            int v = q;
            int mn, mx;
            int lb = lower_bound(a.begin(), a.end(), v) - a.begin();
            int temp = lb;
            if(temp == n)
            {
                temp-=1;
            }
            if(a[temp] > v)
            {
                temp--;
                if(temp >= 0) mn = a[temp];
                else mn = -1;
            }
            else{
                mn = a[temp];
            }
            

            temp = lb;

            if(lb >= n)
            {
                mx = -1;
            }
            else{
                mx = a[lb];
            }

            ans.push_back({mn, mx});
        }
        return ans;
    }
};