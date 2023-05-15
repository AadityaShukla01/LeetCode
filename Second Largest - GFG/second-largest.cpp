//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
	    // code here
	    int maxi=0;
	    int in=0;
	    for(int i=0;i<n;i++){
	        if(arr[i]>maxi){
	        maxi=arr[i];
	        in=i;
	        }
	    }
	   // arr[in]=-1;
	    int ans=0;
	    for(int i=0;i<n;i++){
	        if(arr[i]>ans && arr[i]<maxi){
	        ans=arr[i];
	        in=i;
	        }
	    }
	    if(ans==0 && maxi!=0)
	    return -1;
	    return ans;
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
        auto ans = ob.print2largest(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends