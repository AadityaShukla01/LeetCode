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
    bool eCheck(vector<int>ans){
        int n=ans.size();
        if(n==1){
            return ans[0]%2==0;
        }
        for(int i=1;i<n;i++){
            if(ans[i] %2 != 0)
                return false;
            if(ans[i-1]<=ans[i])
                return false;
        }
        return true;
    }
    bool oCheck(vector<int>ans){
        int n=ans.size();
        if(n==1){
            return ans[0]%2;
        }
        for(int i=1;i<n;i++){
            if(ans[i] %2 == 0)
                return false;
            if(ans[i-1]>=ans[i])
                return false;
        }
        return true;
    }
    bool isEvenOddTree(TreeNode* root) {
        if(root == NULL)
            return false;
        if(root->val %2==0)
            return false;
        queue<TreeNode *>q;
        q.push(root);
        bool flag=false;
        while(q.empty() == false){
            int s=q.size();
            vector<int>ans;
            for(int i=0;i<s;i++){
                TreeNode *node=q.front();
                q.pop();

                ans.push_back(node->val);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            if(!flag){
                if(oCheck(ans)==false)
                    return false;
            }
            else{
                if(eCheck(ans)==false)
                    return false;
            }
            flag =!flag;
        }
        return true;
    }
};