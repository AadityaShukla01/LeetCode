//{ Driver Code Starts
// C++ program to find minimum swaps
// required to group all 1's together
#include <bits/stdc++.h>

using namespace std;

// Function to find minimum swaps
// to group all 1's together
int minSwaps(int arr[], int n);

// Driver Code
int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        cout << minSwaps(a, n) << endl;
    }

    return 0;
}

// } Driver Code Ends


int minSwaps(int arr[], int n) {

    // Complete the function
    int len = 0;
    for(int i=0;i<n;i++){
        if(arr[i] == 1)
            len++;
    }
    int count = len;
    int sum = 0;
    for(int i=0;i<len;i++){
        sum = sum +arr[i];
    }
    if(count == 0) return -1;
    int maxSum = sum;
    
    for(int i=len;i<n;i++){
        sum -= arr[i-len];
        sum += arr[i];
        
        maxSum= max(maxSum, sum);
    }
    
    return count-maxSum;
}