//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int sol(int W,int wt[],int val[],int n,vector<vector<int>>&dp){
        //base case hamesha smallest possible input ko analyse kare
        //agar capacity zero hain to koi saman hi ni daal paoge
        if(n==0 || W==0){
            return 0;
        }
        if(wt[n-1]>W){ //exclude karo agar size se upar hain to
            return sol(W,wt,val,n-1,dp);
        }
        if(dp[W][n]!=-1)
        return dp[W][n];
        
        int a,q;
        if(wt[n-1]<=W){ //include
            a=val[n-1]+sol(W-wt[n-1],wt,val,n-1,dp);
        }
        q=sol(W,wt,val,n-1,dp);//exclude
        
        return dp[W][n]=max(q,a);//inclued or exclude me se jo bada hain use return karo
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
      vector<vector<int>> dp( W+1 , vector<int> (n+1, -1)); 
       return sol(W,wt,val,n,dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends