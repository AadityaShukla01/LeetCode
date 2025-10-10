class Solution {
public:
    int dp[501][501];
    int sol(int i, int j, string& s1, string& s2) {
        if (i < 0)
            return j + 1;
        if (j < 0)
            return i + 1;
        if (dp[i][j] != -1)
            return dp[i][j];

        if (s1[i] == s2[j]) {
            return dp[i][j] = sol(i - 1, j - 1, s1, s2);
        } else {
            return dp[i][j] =
                       1 + min({sol(i - 1, j, s1, s2), sol(i, j - 1, s1, s2),
                                sol(i - 1, j - 1, s1, s2)});
        }
    }
    int minDistance(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        memset(dp, -1, sizeof(dp));
        return sol(n - 1, m - 1, s1, s2);
    }
};