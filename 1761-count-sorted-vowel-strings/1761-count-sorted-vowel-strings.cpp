class Solution {
public:
    int dp[51][6];
    int sol(int i, int pre, int n, vector<char>&s)
    {
        if(i >= n) return 1;
        if(dp[i][pre] != -1) return dp[i][pre];
        int ans = 0;
        for(int j=pre; j<s.size(); j++){
            int steps = sol(i + 1, j, n, s);
            ans += steps;
        }
        return dp[i][pre] = ans;
    }
    int countVowelStrings(int n) {
        vector<char>s = {'a', 'e', 'i', 'o', 'u'};
        memset(dp, -1, sizeof(dp));
        return sol(0, 0, n, s);
    }
};