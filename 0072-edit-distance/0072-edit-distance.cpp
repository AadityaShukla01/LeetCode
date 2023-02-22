class Solution
{
public:
    int om(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
    {
        // base case
        if (i < 0)
            return j + 1;

        if (j < 0)
            return i + 1;

        if(dp[i][j]!=-1)
        return dp[i][j];

        if (s1[i] == s2[j])
            return dp[i][j]= 0 + om(i - 1, j - 1, s1, s2, dp);
        else
        { // delete           //replace              //insert
            return dp[i][j]= min(1+om(i - 1, j, s1, s2, dp), min( 1+om(i - 1, j - 1, s1, s2, dp),  1+om(i, j - 1, s1, s2, dp)));
        }
    }
    int minDistance(string s, string t)
    {
        int m = s.size();
        int n = t.size();
        if(s==t)
        return 0;

        if(m==0)
        return n;

        if(n==0)
        return m;

        vector<vector<int>> dp(m, vector<int>(n+1, -1));
        return om(m - 1, n - 1, s, t, dp);
    }
};