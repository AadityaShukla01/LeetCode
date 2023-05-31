//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        // Your code goes here
        int k =0;
        int len = INT_MAX;
        long long sum =0;
        for(int i =0;i<n;i++){
            sum = sum + arr[i];
            if(sum>x){
                // len = min(len,i-k+1);
                while(sum>x){
                    sum = sum - arr[k];
                    k++;
                }
                len = min(len,i-k+2);
            }
        }
        if(len == INT_MAX) return 0;
        return len;
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}
// } Driver Code Ends