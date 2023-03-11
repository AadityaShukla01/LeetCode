//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int sol(vector<int>arr, int sum,int i,vector<vector<int>>&dp){
        if(i==0)
        return arr[i]==sum;
        
        if(sum==0) return 1;
        
        if(dp[i][sum]!=-1) return dp[i][sum];
        
        return dp[i][sum]=sol(arr,sum-arr[i],i-1,dp)|| sol(arr,sum,i-1,dp);
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return sol(arr,sum,n-1,dp);
    }
    int equalPartition(int N, int arr[])
    {
        int sum=0;
        for(int i=0;i<N;i++)
         sum=sum+arr[i];
         
         vector<int>temp;
         for(int i=0;i<N;i++)
         temp.push_back(arr[i]);
         
         if(sum%2!=0) return 0;
         else return isSubsetSum(temp,sum/2);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends