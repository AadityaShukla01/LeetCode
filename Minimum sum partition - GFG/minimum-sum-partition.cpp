//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
  int sol(int arr[],int n,int Range,vector<vector<int>> &dp){
      for(int i=0;i<n+1;i++){
          for(int j=0;j<Range+1;j++){
              if(i==0)
              dp[i][j]=0;
              
              if(j==0)
              dp[i][j]=1;
          }
      }
       for(int i=1;i<n+1;i++){
          for(int j=0;j<Range+1;j++){
              if(arr[i-1]<=j){
                  dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
              }
              else{
                  dp[i][j]=dp[i-1][j];
              }
          }
       }
       int diff=INT_MAX;
      
         for(int i=Range/2;i>=0;i--)
	   {
	       if(dp[n][i]==true)
	       {
	           diff=Range-2*i;
	           break;
	       }
	   }
	   return diff;
  }
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum=0;
	    for(int i=0;i<n;i++)
	    sum=sum+arr[i];
	    vector<vector<int>> dp( n+1 , vector<int> (sum+1,0));
	    return sol(arr,n,sum,dp);
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends