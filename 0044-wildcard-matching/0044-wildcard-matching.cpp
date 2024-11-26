class Solution {
public:
    int dp[2001][2001];
    bool sol(int i, int j, string &s, string &p, int n, int m){
        if(i >= n)
        {
            for(int l=j; l<m; l++){
                if(p[l] != '*') return false;
            }
            return true;
        }

        if(j >= m) return false;

        if(dp[i][j] != -1)
            return dp[i][j];

        bool ans = false;

        if(s[i] == p[j])
        {
            ans |= sol(i + 1, j + 1, s, p, n, m);
        }
        else if(p[j] == '?')
        {
            ans |= sol(i + 1, j + 1, s, p, n, m);   
        }
        else if(p[j] == '*'){
            ans |= sol(i + 1, j + 1, s, p, n, m);   
            ans |= sol(i + 1, j, s, p, n, m); 
            ans |= sol(i, j + 1, s, p, n, m);     
        }
        else return dp[i][j] = false;

        return dp[i][j] = ans;
    }
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        memset(dp, -1, sizeof(dp));
        return sol(0, 0, s, p, n, m);
    }
};