class Solution {
public:
    double dp[26][26][101];
    double total(int r, int c, int n, int k)
    {
        if(k < 0) return 0.0;
        if(r < 0 || c < 0 || r >= n || c >= n) return 0.0;
        if(k == 0) return 1.0;

        if(dp[r][c][k] != 0) 
            return dp[r][c][k];
            
        double ans = 0;

        int dx[] = {1, -1, 1, -1, 2, -2, 2, -2};
        int dy[] = {2, 2, -2, -2, 1, 1, -1, -1};

        for(int i=0; i<8; i++)
        {
            int nr = r + dx[i];
            int nc = c + dy[i];

            double val = 1.0/8;
            double res = total(nr, nc, n, k - 1) * val;

            ans += 1.0 * res;
        }
        return dp[r][c][k] = ans;
    }
    double knightProbability(int n, int k, int row, int column) {
        memset(dp, 0, sizeof(dp));
        double a = total(row, column, n, k);
        return a;
    }
};