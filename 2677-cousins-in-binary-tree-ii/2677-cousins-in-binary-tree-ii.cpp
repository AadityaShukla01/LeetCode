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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(!root) return NULL;
        queue<TreeNode*>q;
        q.push(root);

        // find children sum
        // for every node in bfs subtract its children sum
        // remaning sum -> cousin sum
        root->val = 0;
        while(q.empty() == false){
            int sz = q.size();
            int sum = 0;
            vector<TreeNode*>temp;
            for(int i=0; i<sz; i++)
            {
                auto src = q.front();
                q.pop();
                temp.push_back(src);
                if(src->left){
                    sum += src->left->val;
                    q.push(src->left);
                }
                if(src->right){
                    sum += src->right->val;
                    q.push(src->right);
                }
            }

            for(auto el: temp){
                int t = sum;

                if(el->left) t -= el->left->val;
                if(el->right) t -= el->right->val;

                if(el->left) el->left->val = t;
                if(el->right) el->right->val = t;
            }
        }
        return root;
    }
};