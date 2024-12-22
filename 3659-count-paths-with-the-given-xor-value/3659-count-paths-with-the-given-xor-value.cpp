class Solution {
public:
    int dp[301][301][17];
    const int mo = 1e9 + 7;
    int sol(int r, int c, int xorr, int k, int n, int m, vector<vector<int>>&g)
    {
        if(r == n - 1 && c == m - 1)
            return (xorr ^ g[r][c]) == k;

        if(r >= n || c >= m) return 0;

        if(dp[r][c][xorr] != -1)
            return dp[r][c][xorr];

        int down = sol(r + 1, c, xorr ^ g[r][c], k, n, m, g);
        int ryt = sol(r, c + 1, xorr ^ g[r][c], k, n, m, g);


        return dp[r][c][xorr] = (ryt % mo + down % mo) % mo;
    }
    int countPathsWithXorValue(vector<vector<int>>& g, int k) {
        int n = g.size(), m = g[0].size();
        memset(dp, -1, sizeof(dp));
        return sol(0, 0, 0, k, n, m, g);
    }
};