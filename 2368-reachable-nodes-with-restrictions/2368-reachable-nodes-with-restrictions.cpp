class Solution {
public:
    void dfs(int node,vector<int>adj[],int &cost,vector<int> &vis){
        vis[node]=1;
        for(auto it:adj[node]){
            if(vis[it]==0){
                dfs(it,adj,cost,vis);
            }
        }
        cost++;
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        //create adjcenty list
        vector<int>adj[n];
        vector<int>vis(n,0);

        for(auto it:edges){
            int a=it[0];
            int b=it[1];

            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for(int i=0;i<restricted.size();i++){
            vis[restricted[i]]=1;
        }
        int cost=0;
        
          
        dfs(0,adj,cost,vis);
            
        return cost;
    }
};