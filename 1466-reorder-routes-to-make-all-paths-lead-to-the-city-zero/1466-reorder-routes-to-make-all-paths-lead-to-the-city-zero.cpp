class Solution {
public:
    int vis[100001];
    int dfs(int node,vector<vector<int>>&adj){
        vis[node]=1;
        int res=0;
        for(auto it:adj[node]){
            if(!vis[abs(it)]){
                    res+= dfs(abs(it),adj)+(it>0);
            }
        }
        return res;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        vector<int>vis(n,0);
        for(auto &it:connections){
            int a=it[0];
            int b=it[1];

            adj[a].push_back(b);
            adj[b].push_back(-a);
        }

       return dfs(0,adj);
    }
};