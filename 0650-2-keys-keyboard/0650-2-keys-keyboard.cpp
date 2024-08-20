class Solution {
public:
    int dp[1001][1001];
    int sol(int i, int copied, int n){
        if(i > n) return 1e9;
        if(i == n) return 0;
        if(dp[i][copied] != -1) return dp[i][copied];
        int paste = 1e9;
        if(copied)
            paste = sol(i + copied, copied, n) + 1;

        int copy = sol(i + i, i, n) + 2;

        return dp[i][copied] = min(copy, paste);
    }
    int minSteps(int n) {
        memset(dp, -1, sizeof(dp));
        return sol(1, 0, n);
    }
};