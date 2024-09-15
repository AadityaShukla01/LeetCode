class Solution {
public:
    long long dp[4][100001];
    long long sol(int i, int j, vector<int>&a, vector<int>&b)
    {
        if(i >= a.size()) return 0;
        if(j >= b.size()) return -1e15;

        if(dp[i][j] != -1) return dp[i][j];
        long long ans = 0;

        long long p = sol(i + 1, j + 1, a, b) + 1LL*a[i] * b[j];
        long long np = sol(i, j + 1, a, b);

        return dp[i][j] = max(p, np);
    }
    long long maxScore(vector<int>& a, vector<int>& b) {
        memset(dp, -1, sizeof(dp));
        return sol(0, 0, a, b);
    }
};