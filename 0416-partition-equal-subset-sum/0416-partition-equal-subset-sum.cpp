class Solution {
public:
   bool sol(vector<int>arr, int sum,int n,vector<vector<int>>&dp){
        if(sum==0)
        return true ;//empty subset {}
        
        if(n==0)
        return false; //if sum!-0 && n==0 no possble subset found
            
        if(dp[n][sum]!=-1)//age matrix me values store kar liya to return karo answer
        return dp[n][sum];
        
        if(arr[n-1]<=sum){ //include if numbe rless than sum
            dp[n][sum]=sol(arr,sum-arr[n-1],n-1,dp) || sol(arr,sum,n-1,dp);
        }
        else{//exclude no if no in array is less than sum
            dp[n][sum]=sol(arr,sum,n-1,dp);
        }
        return dp[n][sum];
    }
        
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
        }
        vector<vector<int>> dp( nums.size()+1 , vector<int> (sum+1, -1));
        if(sum % 2 != 0)
        return false;
        return sol(nums,sum/2,nums.size(),dp);
    }
};