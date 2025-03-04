class Solution {
public:
    int adj(char x, char y)
    {
        int op1 = abs(x - y);
        int op2 = 26 - op1;
        return min(op1, op2);
    }
    int dp[201][201][201];     
    int sol(int l, int r, int k, string &s)
    {
        if(l > r) return 0;
        if(l == r) return 1;
        if(dp[l][r][k] != -1)
            return dp[l][r][k];
        int ans = 0;
        if(s[l] == s[r])
        {
            ans = max(ans, sol(l + 1, r - 1, k, s) + 2);
        }

        if(adj(s[l], s[r]) <= k)
        {
            ans = max(ans, sol(l + 1, r - 1, k - adj(s[l], s[r]), s) + 2);
        }

        ans = max(ans, sol(l + 1, r, k, s));
        ans = max(ans, sol(l, r - 1, k, s));

        return dp[l][r][k] = ans;
    }
    int longestPalindromicSubsequence(string s, int k) {
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        return sol(0, n - 1, k, s);
    }
};