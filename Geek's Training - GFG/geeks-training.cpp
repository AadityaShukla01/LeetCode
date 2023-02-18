//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int sol(int day,int lastDay,vector<vector<int>>& points,vector<vector<int>>&dp){
      if(day==0){
          int maxi=0;
          for(int i=0;i<3;i++){
              if(i!=lastDay)
              maxi=max(maxi,points[0][i]);
          }
          return maxi;
      }
          int maxi=0;
          if(dp[day][lastDay]!=-1)
          return dp[day][lastDay];
          
          
      for(int i=0;i<3;i++){
          if(i!=lastDay){
              int cost=points[day][i]+sol(day-1,i,points,dp);
              maxi=max(maxi,cost);
          }
      }
      return dp[day][lastDay]=maxi;
  }
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        // vector<int>dp(n+1,-1);
        vector<vector<int>>dp(n,vector<int>(4,-1));
        return sol(n-1,3,points,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends