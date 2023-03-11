//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

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
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends