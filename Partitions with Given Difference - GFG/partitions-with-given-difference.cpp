//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
   int sol(int i ,int target ,vector<int>&arr,vector<vector<int>>&dp){
	      
	      if(i==0){
	          if(target==0 && arr[0]==0)
	          return 2;
	          if(target==0 || arr[0]==target)
	          return 1;
	          return 0;
	      }
	      
	      if(dp[i][target]!=-1)
	      return dp[i][target];
	      
	      int pick=0;
	      
	      if(arr[i]<=target){
	          pick=sol(i-1,target-arr[i],arr,dp);
	      }
	      int notPick=sol(i-1,target,arr,dp);
	      
	      return dp[i][target]=(pick+notPick)%(1000000007); // since we need total count we always add
	  }

    int countPartitions(int n, int target, vector<int>& nums) {
         int sum = 0;
        for(int x: nums)
            sum += x;
        if (abs(target) > sum || (sum + target) % 2 != 0){ 
            return 0;
        }
        int s1 = (sum + target)/2;
        vector<vector<int>> dp( n , vector<int> (s1+1,-1));
        int ans = sol(n-1,s1,nums,dp);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends