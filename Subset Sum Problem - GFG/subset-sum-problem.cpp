//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool sol(vector<int>arr, int target,int n,vector<vector<int>>&dp){
        if(target==0)
        return true;
        
        if(n==0)
        return arr[0]==target;
        
        if(dp[n][target]!=-1)
        return dp[n][target];
        
        bool ok=false;
        
        if(target>=arr[n]){
            ok=sol(arr,target-arr[n],n-1,dp);
        }
        
        bool notok=sol(arr,target,n-1,dp);
        
        return dp[n][target]=(ok||notok);
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
        vector<vector<int>> dp( n+1 , vector<int> (sum+1, -1));
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