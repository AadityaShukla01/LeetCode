class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<pair<int,int>>adj[n];
        for(auto it : redEdges){
            adj[it[0]].push_back({it[1],1});
        }
        for(auto it : blueEdges){
            adj[it[0]].push_back({it[1],0});
        }
        vector<int>color(n,-1);
        queue<vector<int>> q;
        vector<int>ans;
        q.push({0,0,-1});
        vector<int>dist(n,1e9);
        dist[0] = 0;
        //this is the main catch int this problem
        vector<vector<int>>vis(n,vector<int>(2,0));
        vis[0][0] = 1;
        vis[0][1] = 1;
        while(q.empty()==false){
            int node = q.front()[0];
            int steps = q.front()[1];
            int color = q.front()[2];
            q.pop();
            
            for(auto it : adj[node]){
                int u = it.first;
                int colorNew = it.second;
                if(colorNew != color && vis[u][colorNew]==0){
                    if(dist[u] == 1e9)
                        dist[u] = steps + 1;
                    q.push({u,steps+1,colorNew});
                    vis[u][colorNew] = 1;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(dist[i] == 1e9)
                dist[i] = -1;
        }
        return dist;
    }
};