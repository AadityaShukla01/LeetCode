//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	    vector<string>ans;
	    set<string>st;
	    void sol(int i, int n, string &temp, string s){
	        if(i >= n){
	            if(st.find(temp) == st.end()){
	                ans.push_back(temp);
	                st.insert(temp);
	            }
	            return;
	        }
	        
	        if(s[i] == '?'){
	            temp += '1';
	            sol(i+1, n, temp, s);
	            temp.pop_back();
	            temp += '0';
	            sol(i+1, n, temp, s);
	            temp.pop_back();
	        }
	        else{
	            temp += s[i];
	            sol(i+1, n, temp, s);
	            temp.pop_back();
	        }
	    }
		vector<string> generate_binary_string(string s)
		{
		    // Code here
		    int n = s.size();
		    string temp;
		    sol(0, n, temp, s);
		    sort(ans.begin(), ans.end());
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string s;
	    cin >> s;
	    Solution ob;
	    vector<string> ans = ob.generate_binary_string(s);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}
// } Driver Code Ends