class Solution {
public:
    int dp[100001][2];
    int sol(int i, int pre, string &s){
        if(i >= s.size()) return 0;
        if(dp[i][pre] != -1) return dp[i][pre];
        int ans = 1e9;
        if(s[i] == '0'){
            if(pre == 0){
                ans = sol(i+1, 0, s);
            }
            else{
                ans = 1 + sol(i+1, 1, s);
            }
        }
        else{
            if(pre == 0){
                int steps1 = sol(i+1, 1, s);
                int steps2 = sol(i+1, 0, s) + 1;
                ans = min(steps1, steps2);
            }
            else{
                ans = sol(i+1, 1, s);
            }
        }
        return dp[i][pre] = ans;
    }
    int minFlipsMonoIncr(string s) {
        int n = s.size(); 
        memset(dp, -1, sizeof(dp));
        return sol(0, 0, s);   
    }
};