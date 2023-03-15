class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{0,src}});
        vector<pair<int,int>>adj[n];
        
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>dist(n,INT_MAX);

        while(!q.empty()){
            int stops=q.front().first;
            int node=q.front().second.second;
            int distance=q.front().second.first;
            q.pop();
            for(auto it:adj[node]){
                int wt=it.second;
                int neighbour=it.first;

                if(distance+wt <dist[neighbour] && stops<k+1){
                    dist[neighbour]=distance+wt;
                    q.push({stops+1,{dist[neighbour],neighbour}});
                }

            }
        }
        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];
    }
};