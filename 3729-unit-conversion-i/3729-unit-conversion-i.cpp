class Solution {
public:
    vector<pair<int, int>>adj[100001];
    const int mo = 1e9 + 7;     
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        for(auto c: conversions){
            int source = c[0];
            int target = c[1];
            int units = c[2];

            adj[source].push_back({target, units});
        }
        int n = conversions.size() + 1;
        queue<pair<int, long long>>q;
        q.push({0, 1});
        vector<int>vis(n, 0);
        vector<int>ans(n, 1);
        while(q.empty() == false)
        {
            int src = q.front().first;
            long long wt = q.front().second;
            q.pop();
            ans[src] = wt % mo;
            if(vis[src]) continue;
            vis[src] = 1;

            for(auto it: adj[src]){
                q.push({it.first, (1LL * it.second * wt) % mo});
            }
        }
        return ans;
    }
};