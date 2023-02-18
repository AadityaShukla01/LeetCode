class Solution {
public:
    int sol(vector<int>& nums,int n,vector<int>& dp){
        //if n is zeros return only house we see
        if(n==0)
        return nums[0];

        if(n<0)
        return 0;

        if(dp[n]!=-1)
        return dp[n];

        int pick=nums[n]+sol(nums,n-2,dp);
        int notPick=0+sol(nums,n-1,dp);

        dp[n]=max(pick,notPick);

        return dp[n];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        // vector<int>dp(n+1,-1);
        // vector<int>dp(n);

        // dp[0]=0;
        int pre=nums[0];
        int pre2=0;

        for(int i=1;i<n;i++){
            int pick=nums[i];
            if(i>1)
            pick+=pre2;

            int notPick=0+pre;

            int curr=max(pick,notPick);
            pre2=pre;
            pre=curr;

        }
        return pre;
    }
};