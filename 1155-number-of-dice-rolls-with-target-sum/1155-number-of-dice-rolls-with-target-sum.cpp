class Solution {
public:
    int dp[32][1011];
    long long MOD=1e9+7;
    int sol(int i,int k,int target){
        if(target==0 && i==0) return 1;
        if(target<=0 || i<=0) return 0;
        int ans=0;

        if(dp[i][target]!=-1) return dp[i][target];

        for(int lim=1;lim<=k;lim++){
            ans=(ans%MOD+(sol(i-1,k,target-lim))%MOD)%MOD;
        }
        return dp[i][target]=ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        memset(dp,-1,sizeof(dp));
        return sol(n,k,target);
    }
};