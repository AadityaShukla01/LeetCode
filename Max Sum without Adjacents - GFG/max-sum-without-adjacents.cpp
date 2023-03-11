//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int sol(int arr[],int i,vector<int>&dp){
	    if(i==0) return arr[i];
	    if(i<0) return 0;
	    
	    if(dp[i]!=-1) return dp[i];
	    
	    //pick case
	    int a=sol(arr,i-2,dp)+arr[i];
	    int b=sol(arr,i-1,dp);
	    return dp[i]=max(a,b);
	}
	int findMaxSum(int *arr, int n) {
	    // code here
	    vector<int>dp(n+1,-1);
	    return sol(arr,n-1,dp);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends