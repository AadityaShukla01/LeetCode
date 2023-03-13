class Solution {
   int sol(vector<int>&nums,int target,vector<int>&dp,int n)
    {
        if(target==0)
            return 1;

        if(dp[target]!=-1) return dp[target];

        int q=0;
        
       for(int i=0;i<nums.size();i++){
           if(target>=nums[i])
            q+=sol(nums,target-nums[i],dp,n);
       }
       return dp[target]=q;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>dp(target+1,-1);
        return sol(nums,target,dp,n);
    }
};