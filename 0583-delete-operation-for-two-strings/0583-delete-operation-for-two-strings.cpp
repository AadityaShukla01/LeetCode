class Solution {
public:
    int dp[2001][2001];
    int sol(int i, int j, int n, int m, string &s1, string &s2)
    {
        if(i >= n || j >= m) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if(s1[i] == s2[j]){
            ans = sol(i + 1, j + 1, n, m, s1, s2) + 1;
        }
        else{
            int op1 = sol(i + 1, j, n, m, s1, s2);
            int op2 = sol(i, j + 1, n, m, s1, s2);

            ans = max(op1, op2);
        }
        return dp[i][j] = ans;
    }
    int minDistance(string w1, string w2) {
        int n = w1.size(), m = w2.size();
        memset(dp, -1, sizeof(dp));
        int a = sol(0, 0, n, m, w1, w2);

        return n + m - 2*a;
    }
};