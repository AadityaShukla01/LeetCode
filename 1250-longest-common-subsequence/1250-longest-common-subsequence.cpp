class Solution {
public:
    //time complecity->2^m*2^n
    int dp[1001][1001];
    int sol(int i, int j, int n, int m, string &s1, string &s2){
        if(i >= n) return 0;
        if(j >= m) return 0;
        if(dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;
        if(s1[i] == s2[j]){
            ans = max(ans, 1 + sol(i+1, j+1, n, m, s1, s2));
        }
        else{
            int p1 = sol(i+1, j, n, m, s1, s2);
            int p2 = sol(i, j+1, n, m, s1, s2);

            ans = max({ans, p1, p2});
        }
        return dp[i][j] = ans;
    }
    int longestCommonSubsequence(string t1, string t2) {
        int n = t1.size();
        int m = t2.size();
        memset(dp, -1, sizeof(dp));
        return sol(0, 0, n, m, t1,t2);
    }
};