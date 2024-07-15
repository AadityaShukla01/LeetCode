/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int, int> mp;
        map<int, vector<int>> children;
        for (auto d : descriptions) {
            int p = d[0];
            int c = d[1];
            if (children.find(p) == children.end()) {
                children[p].resize(2, -1e9);
            }
            mp[c]++;
            if (d[2]) {
                children[p][0] = c;
            } else {
                children[p][1] = c;
            }
        }

        queue<TreeNode*> q;
        int par = -1;
        for (auto it : descriptions) {
            if (mp[it[0]] == 0)
                par = it[0];
        }
        TreeNode* root = new TreeNode(par);
        q.push(root);
        while (q.empty() == false) {
            TreeNode* node = q.front();
            q.pop();
            if(children.find(node->val) == children.end()) continue;
            vector<int> it = children[node->val];
            // cout << node->val << "\n";
            if (it[0] != -1e9) {
                node->left = new TreeNode(it[0]);
                q.push(node->left);
            }
            // else if(it[0] == -1e9) node->left = NULL;

            if (it[1] != -1e9) {
                node->right = new TreeNode(it[1]);
                q.push(node->right);
            }
            // else if(it[1] == -1e9) node->right = NULL;
        }

        return root;
    }
};