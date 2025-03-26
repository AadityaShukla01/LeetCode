class Solution {
public:
    int ans;
    int x;
    void sol(int r, int c, int n, int m, vector<vector<int>>& grid, vector<vector<int>>&vis, int median)
    {
        if(ans == -1) return;

        vis[r][c] = 1;

        if(median != grid[r][c]) {
            int diff = grid[r][c] - median;
            if(median > grid[r][c])
            {
                if(abs(diff) % x) ans = -1;
                else ans += abs(diff) / x;
            }
            else{
                if(diff % x) ans = -1;
                else ans += diff / x;
            }
        }

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for(int i=0; i<4; i++)
        {
            int nr = dx[i] + r;
            int nc = dy[i] + c;

            if(nr >= 0 && nr < n && nc >= 0 && nc < m)
            {
                if(!vis[nr][nc]) sol(nr, nc, n, m, grid, vis, median);
            }        
        }
    }

    int minOperations(vector<vector<int>>& g, int x) {
        int median;
        ans = 0;
        this->x = x;
        int n = g.size(), m = g[0].size();
        vector<int>v;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++) v.push_back(g[i][j]);
        }
        sort(v.begin(), v.end());
        int sz = v.size();
        if(sz % 2){
            median = v[sz / 2]; 
        }  
        else{
            median = v[sz / 2 - 1];
        }

        vector<vector<int>>vis(n, vector<int>(m, 0));

        sol(0, 0, n, m, g, vis, median);

        return ans;
    }
};