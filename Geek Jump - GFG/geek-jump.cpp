//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int sol(vector<int>& height, int n,vector<int>& dp){
      if(n==0)
      return 0;
      
      if(dp[n]!=-1)
      return dp[n];
      
      int left=sol(height,n-1,dp)+abs(height[n]-height[n-1]);
      int right=INT_MAX;
      if(n>1)
      right=sol(height,n-2,dp)+abs(height[n]-height[n-2]);
      
      dp[n]=min(right,left);
      
      return dp[n];
  }
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int>dp(n,0);
        //initialise 
        dp[0]=0;
        
        for(int i=1;i<n;i++){
            int left=dp[i-1]+abs(height[i]-height[i-1]);
            int right=INT_MAX;
            
            if(i>1)
            right=dp[i-2]+abs(height[i]-height[i-2]);
            
            dp[i]=min(left,right);
        }
        return dp[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends