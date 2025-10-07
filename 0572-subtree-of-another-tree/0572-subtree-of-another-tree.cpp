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
    bool isSame(TreeNode* p, TreeNode* q){
        if(!p && !q) return true;
        if(!p || !q) return false;
        if(p->val != q->val) return false;

        bool l = isSame(p->left, q->left);
        bool r = isSame(p->right, q->right);

        return l && r;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL) return false;

        if(isSame(root, subRoot)) return true;

        bool l = isSubtree(root->left, subRoot);
        bool r = isSubtree(root->right, subRoot);

        return l || r;
    }
};