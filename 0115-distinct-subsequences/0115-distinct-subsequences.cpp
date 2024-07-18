class Solution {
public:
    int dp[2001][2001];
    int sol(int i, int j, int n, int m, string s, string t){
        if(j == m) return 1;
        if(i >= n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if(s[i] == t[j])
            ans += sol(i+1, j+1, n, m, s, t) + sol(i+1, j, n, m, s, t);
        else
            ans += sol(i+1, j, n, m, s, t);

        return dp[i][j] = ans;

    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        memset(dp, -1, sizeof(dp));
        return  sol(0, 0, n, m, s, t);
    }
};