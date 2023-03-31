class Solution {
public:
    void dfs(int node,vector<int>adj[],vector<int> &res,vector<vector<int>> &ans,vector<int>&vis){
        vis[node]=1;
        for(auto it:adj[node]){
            if(vis[it]==0){
                res.push_back(it);
                dfs(it,adj,res,ans,vis);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(auto it:edges){
            int a=it[0];
            int b=it[1];
            //reverse the edges
            adj[b].push_back(a);
        }
        vector<vector<int>>ans(n);
        for(int i=0;i<n;i++){
            vector<int>res;
            vector<int>vis(n,0);

            dfs(i,adj,res,ans,vis);

            sort(res.begin(),res.end());
            ans[i]=res;
        }
        return ans;
    }
};