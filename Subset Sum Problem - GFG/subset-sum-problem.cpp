//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool sol(vector<int>arr, int sum,int n,vector<vector<int>>&dp){
        if(sum==0)
        return true ;//empty subset {}
        
        if(n==0)
        return false; //if sum!-0 && n==0 no possble subset found
            
        if(dp[n][sum]!=-1)
        return dp[n][sum];
        
        if(arr[n-1]<=sum){
            dp[n][sum]=sol(arr,sum-arr[n-1],n-1,dp) || sol(arr,sum,n-1,dp);
        }
        else{
            dp[n][sum]=sol(arr,sum,n-1,dp);
        }
        return dp[n][sum];
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
        vector<vector<int>> dp( n+1 , vector<int> (sum+1, -1));
        return sol(arr,sum,n,dp);
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