class Solution {
public:
    vector<int>adj[100001];
    void dfs(int src, vector<int>&col)
    {
        col[src] = 1;

        for(auto node: adj[src])
        {
            if(col[node] == 0) {
                dfs(node, col);
            }
        }
    }
    bool fn(int src, vector<int>&col, vector<int>&vis)
    {
        vis[src] = 1;

        if(col[src]) return true;

        for(auto node: adj[src])
        {

            if(vis[node] == 0)
            {
                if(fn(node, col, vis))
                    return true;
            }
        }
        return false;
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& edges) {
        for(auto e: edges)
        {
            int a = e[0], b = e[1];

            adj[a].push_back(b);
        }
        vector<int>col(n, 0);
        vector<int>vis(n, 0);
        dfs(k, col);
        bool ans = false;
        for(int i=0; i<n; i++)
        {
            if(col[i] == 0 && vis[i] == 0)
            {
                ans |= fn(i, col, vis);
            }
        }
        vector<int>res;
        if(ans)
        {
            for(int i=0; i<n; i++)
            {
                res.push_back(i);
            }
            return res;
        }
        else {
            for(int i=0; i<n; i++)
            {
                if(!col[i])
                    res.push_back(i);
            }
            return res;
        }
    }
};