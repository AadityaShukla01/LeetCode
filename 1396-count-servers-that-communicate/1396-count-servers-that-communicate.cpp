class Solution {
public:
    void sol(int r, int c, vector<vector<int>>&vis, int n, int m, vector<vector<int>>& g, int &count)
    {
        for(int i=0; i<m; i++)
        {
            if(g[r][i] == 1 && vis[r][i] == 0)
            {
                vis[r][i] = 1;
                count++;
                sol(r, i, vis, n, m, g, count);
            }
        }

        for(int i=0; i<n; i++)
        {
            if(g[i][c] == 1 && vis[i][c] == 0)
            {
                vis[i][c] = 1;
                count++;
                sol(i, c, vis, n, m, g, count);
            }
        }
    }
    int countServers(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
        int cnt2 = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(g[i][j] == 1 && vis[i][j] == 0)
                {
                    vis[i][j] = 1;
                    int count = 0;
                    sol(i, j, vis, n, m, g, count);
                    if(count == 0) cnt2++;
                }
            }
        }

        int cnt = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(vis[i][j] && g[i][j]) cnt++;
            }
        }
        return cnt - cnt2; 
    }
};