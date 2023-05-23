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
    unordered_map<int,int>parent;
    void findParent(TreeNode *root){
        if(root==NULL)
            return ;
        if(root->left){
            parent[root->left->val]=root->val;
            findParent(root->left);
        }
        if(root->right){
            parent[root->right->val]=root->val;
            findParent(root->right);
        }
    }
    bool isCousins(TreeNode* root, int x, int y) {
        int l=0;
        queue<TreeNode *>q;
        q.push(root);
        findParent(root);
        int ans=0;
        int level=0;
        // cout<<parent[x]<<" "<<parent[y]<<endl;
        if(parent[x] == parent[y])
            return false;
        while(q.empty()==false){
            int s=q.size();
            l++;
            for(int i=0;i<s;i++){
                TreeNode *n=q.front();
                q.pop();

                if(n->val ==x || n->val==y){
                    if(ans==0)
                        ans=l;
                    level+=l;
                }
                if(n->left)
                    q.push(n->left);
                if(n->right)
                    q.push(n->right);
            }
        }
        cout<<ans<<level<<endl;
        return (2*ans==level);
    }
};