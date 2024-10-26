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
    map<int, vector<pair<int, int>>>mp;
    map<int, int>height;
    map<int, int>level;
    static bool cmp(const pair<int, int>&a, const pair<int, int>&b)
    {
        return a.second > b.second;
    }
    int getHeight(TreeNode* root)
    {
        if(!root) return 0;

        int l = getHeight(root->left);
        int r = getHeight(root->right);

        height[root->val] = max(l, r) + 1;

        return max(l, r) + 1;
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        queue<TreeNode*>q;
        vector<int>ans;
        getHeight(root);
        q.push(root);

        int l = 0;
        while(q.empty() == false)
        {
            l++;
            int sz = q.size();
            for(int i=0; i<sz; i++)
            {
                TreeNode* src = q.front();
                q.pop();
                level[src->val] = l;
                mp[l].push_back({src->val, height[src->val]});

                if(src->left) q.push(src->left);
                if(src->right) q.push(src->right);
            }

            sort(mp[l].begin(), mp[l].end(), cmp);
        }

        for(int i=0; i<queries.size(); i++)
        {
            int src = queries[i];
            int l = level[src];
            bool f = 0;
            for(int j=0; j<mp[l].size(); j++)
            {
                if(mp[l][j].first != src)
                {
                    ans.push_back(mp[l][j].second + l - 2);
                    f = 1;
                    break;
                }
            }
            if(!f)
            {
                ans.push_back(l - 2);
            }
        }
        return ans;
    }
};