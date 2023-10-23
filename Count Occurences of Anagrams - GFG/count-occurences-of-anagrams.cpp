//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	    int n = pat.size();
	    map<char, int>mapp;
	    
	    for(auto it: pat)
	        mapp[it]++;
	        
	    map<char, int>temp;
	    
	    for(int i=0; i<n; i++)
	        temp[txt[i]]++;
	        
	    int c = 0;
	    
	    if(mapp == temp)
	        c++;
	    
	    for(int i=n; i<txt.size(); i++){
	        temp[txt[i - n]]--;
	        
	        if(temp[txt[i - n]] == 0)
	            temp.erase(txt[i - n]);
	            
	        temp[txt[i]]++;
	        
	        if(mapp == temp)
	            c++;
	    }
	    return c;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends