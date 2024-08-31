class Solution {
public:
    int dp[2001][2001];
    int sol(int r, int c, int n, int m, vector<vector<int>>& g)
    {
        if(dp[r][c] != -1) return dp[r][c];
        int ans = 0;
        int dx[] = {-1, 0, 1};
        int dy[] = {1, 1, 1};

        for(int i=0; i<3; i++){
            int nr = r + dx[i];
            int nc = c + dy[i];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m)
            {
                if(g[nr][nc] > g[r][c])
                {
                    int steps = sol(nr, nc, n, m, g) + 1;
                    ans = max(ans, steps);
                }
            }
        }
        return dp[r][c] = ans;
    }
    int maxMoves(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        int ans = 0;
        
        memset(dp, -1, sizeof(dp));
        for(int i=0; i<n; i++){
            ans = max(ans, sol(i, 0, n, m, g));
        }
        
        return ans;
    }
};