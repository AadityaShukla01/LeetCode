//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        const int prime = 3;
        string pat;
        int len;
        vector <int> search(string pat, string txt)
        {
            //code here.
            // pat = pat;
            len = pat.size();
            vector<int>ans;
            int tru = calculate(pat, 0, len - 1);
            int no = calculate(txt, 0, len - 1);
            if(tru == no){
                if(comp(pat, txt, 0))  ans.push_back(1);
            }
            for(int j=len; j<txt.size(); j++){
                no = recalculate(txt, j-len+1, j, no);
                if(no == tru){
                    if(comp(pat, txt, j-len+1)) ans.push_back(j - len + 2);
                }
            }
            if(ans.size() == 0)  {
                return {-1};
                
            }
            return ans;
        }
        int calculate(string s, int st, int en){
            int sum = 0;
            for(int i=st; i<=en; i++){
                sum = sum + pow(prime, i)*s[i];
            }
            return sum;
        }
        
        int recalculate(string s, int st, int en, int sum){
            int n = s.size();
            sum -= s[st - 1];
            sum = sum/prime;
            sum += s[en]*pow(prime, len - 1);
            return sum;
        }
        
        bool comp(string s, string t, int st){
            for(int i=0; i<s.size(); i++){
                if(s[i] != t[st + i])
                    return false;
            }
            return true;
        }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends