//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) {
        // code here
        int maxi=0;
        int open=0;
        int close=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')
            open++;
            else close++;
            if(open==close)
            maxi=max(maxi,open+close);
            else if(close>open){
                open=0;
                close=0;
            }
        }
        open=0;
        close=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='(')
            open++;
            else close++;
            if(open==close)
            maxi=max(maxi,open+close);
            else if(open>close){
                open=0;
                close=0;
            }
        }
        return maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}

// } Driver Code Ends