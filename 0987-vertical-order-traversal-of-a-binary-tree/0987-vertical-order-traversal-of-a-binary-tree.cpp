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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>nodes;
        queue<pair<TreeNode *,pair<int,int>>>bfs;

        bfs.push({root,{0,0}});

        while(bfs.empty()==false){
            TreeNode *node=bfs.front().first;
            int x=bfs.front().second.first;
            int y=bfs.front().second.second;
            bfs.pop();

            nodes[x][y].insert(node->val);

            if(node->left)
                bfs.push({node->left,{x-1,y+1}});
            if(node->right)
                bfs.push({node->right,{x+1,y+1}});
        }

        vector<vector<int>>ans;
        for(auto it:nodes){
            vector<int>res;
            for(auto n:it.second)
                res.insert(res.end(),n.second.begin(),n.second.end());
                
            ans.push_back(res);
        }
        return ans;
    }
};