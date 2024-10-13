class Solution {
public:
    const int mo = 1e9 + 7;
    int dp[1001][2001][4];
    int sol(int i, string& s, int score, int pre) {
        if (i >= s.size())
            return score > 0;
        if (dp[i][score + 1000][pre] != -1)
            return dp[i][score + 1000][pre];
        long long ans = 0;
        if (pre == 3) {
            if (s[i] == 'F') {
                ans += sol(i + 1, s, score, 0);
                ans += sol(i + 1, s, score - 1, 1);
                ans += sol(i + 1, s, score + 1, 2);
                ans %= mo;
            } else if (s[i] == 'W') {
                ans += sol(i + 1, s, score - 1, 0);
                ans += sol(i + 1, s, score + 1, 1);
                ans += sol(i + 1, s, score, 2);
                ans %= mo;
            } else {
                ans += sol(i + 1, s, score + 1, 0);
                ans += sol(i + 1, s, score, 1);
                ans += sol(i + 1, s, score - 1, 2);
                ans %= mo;
            }
        }

        else {
            if (s[i] == 'F') {
                if (pre != 0)
                    ans += sol(i + 1, s, score, 0);
                if (pre != 1)
                    ans += sol(i + 1, s, score - 1, 1);
                if (pre != 2)
                    ans += sol(i + 1, s, score + 1, 2);
                ans %= mo;
            } else if (s[i] == 'W') {
                if (pre != 0)
                    ans += sol(i + 1, s, score - 1, 0);
                if (pre != 1)
                    ans += sol(i + 1, s, score + 1, 1);
                if (pre != 2)
                    ans += sol(i + 1, s, score, 2);
                ans %= mo;
            } else {
                if (pre != 0)
                    ans += sol(i + 1, s, score + 1, 0);
                if (pre != 1)
                    ans += sol(i + 1, s, score, 1);
                if (pre != 2)
                    ans += sol(i + 1, s, score - 1, 2);
                ans %= mo;
            }
        }
        return dp[i][score + 1000][pre] = ans % mo;
    }
    int countWinningSequences(string s) {
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        return sol(0, s, 0, 3);
    }
};