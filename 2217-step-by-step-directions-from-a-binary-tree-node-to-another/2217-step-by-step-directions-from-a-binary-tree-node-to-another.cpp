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
    TreeNode* target;
    unordered_map<TreeNode*, TreeNode*> parent;
    unordered_set<int> set;
    string ans;
    void getParent(TreeNode* root) {
        if (root == NULL)
            return;

        if (root->left) {
            parent[root->left] = root;
            getParent(root->left);
        }

        if (root->right) {
            parent[root->right] = root;
            getParent(root->right);
        }
    }
    void findTarget(TreeNode* root, int start) {
        if (root == NULL)
            return;

        if (root->val == start) {
            target = root;
            return;
        }

        findTarget(root->left, start);
        findTarget(root->right, start);
    }
    void sol(TreeNode* root, int target, string& temp) {
        if (root == NULL)
            return;

        if (set.find(root->val) != set.end())
            return;

        set.insert(root->val);

        if (root->val == target) {
            ans = temp;
            return;
        }
        if (root->left) {
            temp += 'L';
            sol(root->left, target, temp);
            temp.pop_back();
        }

        if (root->right) {
            temp += 'R';
            sol(root->right, target, temp);
            temp.pop_back();
        }

        if (parent[root]) {
            temp += 'U';
            sol(parent[root], target, temp);
            temp.pop_back();
        }
    }
    string getDirections(TreeNode* root, int start, int dest) {
        findTarget(root, start);
        getParent(root);
        string temp = "";
        sol(target, dest, temp);
        return ans;
    }
};