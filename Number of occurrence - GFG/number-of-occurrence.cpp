//{ Driver Code Starts

#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
		int  first(int arr[], int n, int x){
    // code here
        int start=0;
        int end=n-1;
        int res=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(arr[mid]==x){
                //aage ke liye check karo
                res=mid;
                end=mid-1;
            }
            else if(arr[mid]>x){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return res;
    }
    int second(int arr[], int n, int x){
        int start=0;
        int end=n-1;
        int res=-1;
        while(start<=end){
            
            int mid=start+(end-start)/2;
            
            if(arr[mid]==x){
                //aage ke liye check karo
                res=mid;
                start=mid+1;
            }
            else if(arr[mid]>x){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return res;
    }
	int count(int arr[], int n, int x) {
	    // code here
	    int a=first(arr,n,x);
	    int p=second(arr,n,x);
	    if(p==-1 && a==-1)
	    return 0;
	    if(p==a)
	    return 1;
	    
	    return p-a+1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends