class Solution {
public:
    int dp[201][201];
    int sol(int start, int end){
        if(start>=end) return 0;
        if(dp[start][end] != -1) return dp[start][end];
        int ans = INT_MAX;
        for(int i=start;i<=end;i++){
            //if we chose i which is obviously wrong since wace are considering worst case
            int small = sol(start,i-1);
            int large = sol(i+1,end);
            //min since we want min amount of money--->we are minimizing the maximum possible cost
            //max because if we have tha tmuch money we will surely win
            ans = min(ans,i + max(small,large));
        }
        return dp[start][end] = ans;
    }
    int getMoneyAmount(int n) {
        memset(dp,-1,sizeof(dp));
        return sol(1,n);
    }
};