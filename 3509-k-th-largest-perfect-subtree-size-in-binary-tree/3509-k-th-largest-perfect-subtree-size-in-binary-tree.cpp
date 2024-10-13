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
    pair<int, int>sol(TreeNode* root)
    {
        if(!root) return {0, 0};

        pair<int, int>l = sol(root->left);
        pair<int, int>r = sol(root->right);


        int p = max(l.first, r.first) + 1;
        int q = l.second + r.second + 1;

        if(l.first == r.first && l.first != -1)
        {
            a.push_back(q);
            return {p, q};
        }
        else
            return {-1, 0};
    }
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        sol(root);
        sort(a.begin(), a.end(), greater<int>());
        // for(auto el: a) cout << el << " ";
        return k <= a.size() ? a[k - 1] : -1;
    }
};