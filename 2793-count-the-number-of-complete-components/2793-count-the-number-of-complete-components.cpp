class Solution {
public:
    vector<int>adj[100001];
    void sol(int src, int &count, int &degreeSum, vector<int>&vis)
    {
        count++;
        degreeSum += adj[src].size();

        vis[src] = 1;

        for(auto node : adj[src]){
            if(!vis[node]){
                sol(node, count, degreeSum, vis);
            }
        }
    }    
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int cnt = 0;
        for(auto e: edges)
        {
            int a = e[0], b = e[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<int>vis(n, 0);
        for(int i=0; i<n; i++)
        {
            if(!vis[i])
            {
                int count = 0, degreeSum = 0;
                sol(i, count, degreeSum, vis);

                if(count * (count - 1) == degreeSum) cnt++;
            }
        }
        return cnt;
    }
};