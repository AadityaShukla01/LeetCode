//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here
        int n = str.size();
        
        unordered_map<char, int>map;
        
        for(auto it: str)
            map[it]++;
        
        int i = 0;
        int j = 0;
        unordered_map<char, int>temp;
        int mini = 1e9;
        while(i < n){
            temp[str[i]]++;
            
            if(temp.size() == map.size()){
                while(temp.size() == map.size()){
                    temp[str[j]]--;
                    mini = min(mini, i - j + 1);
                    if(temp[str[j]] == 0)
                        temp.erase(str[j]);
                    j++;
                }
            }
            i++;
        }
        return mini;
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends