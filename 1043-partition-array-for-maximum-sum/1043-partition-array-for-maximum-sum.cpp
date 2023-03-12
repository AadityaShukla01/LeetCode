class Solution {
public:
    int sol(vector<int>& arr,int i, int k,vector<int>&dp){
        int n=arr.size();
        
        if(i==arr.size()) return 0;

        int len=0;
        int maxi=-1;
        int maxSum=-1;
        int sum=0;

        if(dp[i]!=-1) return dp[i];

        for(int j=i;j<min(i+k,n);j++)
        {
            maxi=max(maxi,arr[j]);
            len++;
            cout<<len<<" ";
            sum=len*maxi+sol(arr,j+1,k,dp);
            maxSum=max(sum,maxSum);
        }
        return dp[i]=maxSum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n+1,-1);
        return sol(arr,0,k,dp);
    }
};