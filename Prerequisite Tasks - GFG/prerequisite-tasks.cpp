//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	int indegree[N]={0};
	   vector<int> adj[N];
	   for(auto it:prerequisites){
	       adj[it.first].push_back(it.second);
	       
	   }
        vector<int>ans;	  
        queue<int>q;
        for(int i=0;i<N;i++){
	   for(auto it:adj[i]){
	        indegree[it]++;
	   
	   }
	   }
	   for(int i=0;i<N;i++){
	       if(indegree[i]==0)
	       q.push(i);
	   }
	   
	   while(q.empty()==false){
	       int topo=q.front();
	       ans.push_back(topo);
	       q.pop();
	       for(auto i:adj[topo]){
	           indegree[i]--;
	           if(indegree[i]==0)
	           q.push(i);
	       }
	   }
	   return ans.size()==N;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends