class Solution
{
public:
    string sol(string x, string y, int n, int m, vector<vector<int>> &dp)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
            }
        }
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < m + 1; j++)
            {
                if (x[i - 1] == y[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        int i = n;
        int j = m;
        string ans = "";
        while (i > 0 && j > 0)
        {
            if (x[i - 1] == y[j - 1])
            {
                ans += x[i - 1];
                i--;
                j--;
            }
            else if (dp[i][j - 1] > dp[i - 1][j])
            {
                ans += y[j - 1];
                j--;
            }
            else
            {
                ans += x[i - 1];
                i--;
            }
        }
        while (i > 0)
        {
            ans += x[i - 1];
            i--;
        }
        while (j > 0)
        {
            ans += y[j - 1];
            j--;
        }
        return ans;
    }
    string shortestCommonSupersequence(string s, string t)
    {
        int i = s.size();
        int size = t.size();
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        string ans = sol(s, t, i, size, dp);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};