//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    void sol(int i, string &temp, int a[], int N, vector<string> &ans, unordered_map<int, string>&map){
        if(i == N){
            ans.push_back(temp);
            return ;
        }
        
        string r = map[a[i]];
        for(int j=0;j<r.size();j++){
            temp+=r[j];
            sol(i+1, temp, a, N, ans, map);
            temp.pop_back();
        }
    }
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        unordered_map<int, string>map;
        map[2] = "abc";
        map[3] = "def";
        map[4] = "ghi";
        map[5] = "jkl";
        map[6] = "mno";
        map[7] = "pqrs";
        map[8] = "tuv";
        map[9] = "wxyz";
        vector<string>ans;
        string temp = "";
        sol(0, temp, a, N, ans, map);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends