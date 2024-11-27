class Solution {
public:
    vector<int>adj[1001];
    int sol(int n)
    {
        queue<int>q;
        q.push(0);
        vector<int>dist(n, 1e9);
        dist[0] = 0;

        while(q.empty() == false)
        {
            int src = q.front();
            q.pop();

            for(auto node: adj[src])
            {
                if(dist[node] > dist[src] + 1)
                {
                    dist[node] = dist[src] + 1;
                    q.push(node);
                }
            }
        }
        return dist[n - 1];
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        
        for(int i=0; i<n-1; i++)
        {
            adj[i].push_back(i + 1);
        }
        
        vector<int>ans;
        for(auto q: queries)
        {

            int a = q[0], b = q[1];
            adj[a].push_back(b);
            ans.push_back(sol(n));
        }
        return ans;
    }
};