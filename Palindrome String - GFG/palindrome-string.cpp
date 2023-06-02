//{ Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	bool sol(int l ,int r, string &S){
	    if(l>r) return true;
	    
	    if(S[l]!=S[r])
	        return false;
	    
	    return sol(l+1,r-1,S);
	        
	}
	int isPalindrome(string S)
	{
	    return sol(0,S.size()-1,S);
	}

};

//{ Driver Code Starts.

int main() 
{
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.isPalindrome(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends