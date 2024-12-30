class Solution {
public:
    const int mo = 1e9 + 7;
    int dp[100001];
    int sol(int i, int zero, int one, int lo, int hi){
        int count = 0;
        if(i >= lo && i <= hi) count++;
        if(i > hi) return 0;

        if(dp[i] != -1)
            return dp[i];

        long long ans = 0;

        ans += count;
        ans += sol(i + zero, zero, one, lo, hi);
        ans += sol(i + one, zero, one, lo, hi);

        return dp[i] = ans % mo;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        int ans = 0;
        memset(dp, -1, sizeof(dp));
        return sol(0, zero, one, low, high);
    }
};