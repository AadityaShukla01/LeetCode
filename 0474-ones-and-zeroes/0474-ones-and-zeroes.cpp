class Solution {
public:
    vector<int> calculate(string &s){
        int ones = 0, zeroes = 0;

        for(auto c: s){
            if(c == '0') zeroes++;
            else ones++;
        }

        return {zeroes, ones};
    }
    int dp[601][101][101];
    int sol(int i, vector<string>&strs, int m, int n){
        if(i >= strs.size()) return 0;

        if(dp[i][m][n] != -1) return dp[i][m][n];

        int np = sol(i + 1, strs, m, n);
        int p = 0;

        vector<int> result = calculate(strs[i]);

        if(m - result[0] >= 0 && n - result[1] >= 0){
            p = sol(i + 1, strs, m - result[0], n - result[1]) + 1;
        }

        return dp[i][m][n] = max(p, np);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp, -1, sizeof(dp));
        return sol(0, strs, m, n);
    }
};