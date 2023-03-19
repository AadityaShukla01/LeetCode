
class Solution {
public:
    bool bfs(int src, int destination,vector<int>adj[],vector<int>vis){
        vis[src]=1;
        queue<int>q;
        q.push(src);

        while(!q.empty()){
            int node=q.front();
            q.pop();

            if(node == destination) return true;
            for(auto it:adj[node]){
                if(vis[it]==0){
                    vis[it]=1;
                    q.push(it);
            }
        }
    }
        return false;
}   
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>adj[n];
        vector<int>vis(n,0);
        //create adjacenncy list
        for(auto it:edges){
            int u=it[0];
            int v=it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        if(bfs(source,destination,adj,vis)) return true;

        return false;
    }
};
