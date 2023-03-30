class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }
        queue<int>q;
        q.push(1);
        int ans=INT_MAX;
        vector<int>vis(n+1,0);
        vis[1]=1;

        while(q.empty()==false){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                ans=min(ans,it.second);
                if(vis[it.first]==0){
                    int a=it.first;
                    int wt=it.second;
                    vis[a]=1;
                    q.push(a);
            }
        }
    }
        return ans;
    }
};