//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        queue<pair<int,int>>q;
        q.push({0,start});
        vector<int>distance(100000,1e9);
        distance[start]=0;
        while(q.empty()==false){
            int count=q.front().first;
            int num=q.front().second;
            q.pop();
        for(int n:arr){
            int newNumber=(num*n) % 100000;
            if(distance[newNumber]>count+1){
                distance[newNumber]=count+1;
                if(newNumber==end)
                return count+1;
                q.push({count+1,newNumber});
            }
        }
    }
    return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends