//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int N, int m, vector<vector<int>> prerequisites) 
    {
        int indegree[N]={0};
	   vector<int> adj[N];
	   for(auto it:prerequisites){
	       adj[it[1]].push_back(it[0]);
	       
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
	   if(ans.size()==N)
	   return ans;
	   
	   return {};
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends