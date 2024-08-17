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
    int sol(TreeNode* root){
        if(!root) return 0;

        int l = sol(root->left);
        int r = sol(root->right);

        int subtreeSum = l + r + root->val;

        mp[subtreeSum]++;

        return l + r + root->val;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        sol(root);

        priority_queue<pair<int, int>>pq;

        for(auto it: mp){
            pq.push({it.second, it.first});
        }

        auto it = pq.top();

        int freq = it.first;
        pq.pop();
        vector<int>ans;
        ans.push_back(it.second);

        while(pq.empty() == false && pq.top().first == freq){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};