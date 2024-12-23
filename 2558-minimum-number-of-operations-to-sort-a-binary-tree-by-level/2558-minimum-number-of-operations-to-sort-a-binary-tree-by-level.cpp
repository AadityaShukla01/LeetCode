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
    int sol(vector<int>&a)
    {
        vector<int>temp = a;
        sort(temp.begin(), temp.end());
        map<int, int>mp;
        int n = temp.size();
        for(int i=0; i<n; i++)
        {
            mp[temp[i]] = i;
        }

        int ops = 0;

        int i = 0;
        while(i < n)
        {
            int correct = mp[a[i]];

            if(correct == i)
            {
                i++;
                continue;
            }
            ops++;
            swap(a[i], a[correct]);
        }
        return ops;
    }
    int minimumOperations(TreeNode* root) {
        int ops = 0;
        queue<TreeNode*>q;
        q.push(root);

        while(q.empty() == false)
        {
            int sz = q.size();
            vector<int>v;
            for(int i=0; i<sz; i++)
            {
                TreeNode* node = q.front();
                q.pop();

                v.push_back(node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            ops += sol(v);
        }
        return ops;
    }
};