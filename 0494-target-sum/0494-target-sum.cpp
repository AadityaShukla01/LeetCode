class Solution {
public:
    //this proble is same as partioning of set to give difefernce k
    // Here we dont have to set t[i][0]=1 for all i because for j=0 (i.e sum=0) subset with value zeros [0,  0, 0] can be formed and that is get counted here;
    // only initialize t/dp[0][0]=1;
// eg. 0 0 2
// if sum=2
    int sol(vector<int> nums,int ans,int n,vector<vector<int>>&dp) {
        dp[0][0]=1;
        for(int i=0;i<n+1;i++){
            for(int j=1;j<ans+1;j++){
                if(i==0)
                dp[i][j]=0; //agar size of array zero hain to koi sum possible ni     
            }
        }
        for(int i=1;i<n+1;i++){
            for(int j=0;j<ans+1;j++) {
                if(nums[i-1]<=j){
                    dp[i][j] = dp[i-1][j-nums[i-1]] +dp[i-1][j]; //elemetn ko pick or na pick karen ki chices
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][ans];
    
    }
    // s1 + s2=sum
    // s1-s2=target
    // s1=(sum+target)/2
    
    int findTargetSumWays(vector<int>& nums, int target) {
        //initialising base case
        int sum=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
            sum=sum+nums[i];
        int ans=(sum+target)/2;

         if (abs(target) > sum || (sum + target) % 2 != 0){ 
            return 0;
        }
        vector<vector<int>> dp( n+1 , vector<int> (ans+1,0));
        return sol(nums,ans,n,dp);
    }
};