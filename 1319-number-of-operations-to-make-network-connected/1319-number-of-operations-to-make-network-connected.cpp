
class Solution {
public:
    int vis[100001];
    void dfs(int node,vector<int>adj[]){
        vis[node]=1;

        for(auto it:adj[node]){
            if(vis[it]==0){
                dfs(it,adj);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int ans=0;
        if(n-1>connections.size()) return -1;
        vector<int>adj[n];
    
        for(auto it:connections){
            int a=it[0];
            int b=it[1];

            adj[a].push_back(b);
            adj[b].push_back(a);
            
        }
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                ans++;
                dfs(i,adj);
            }
        }
        
        return ans-1;

     
    }
};