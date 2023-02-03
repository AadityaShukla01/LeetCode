//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  bool dfs(int node,int V, vector<int> adj[],int  vis[],int pathVis[],int ans[]){
        vis[node]=1;
        pathVis[node]=1;
        
        for(auto i:adj[node]){
            //if not visited 
            if(!vis[i]){
                if(dfs(i,V,adj,vis,pathVis,ans)==true)
                return true;
            }
            else if(pathVis[i]==true){
                return true;
            }
        }
        ans[node]=1;
        pathVis[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
    int vis[V]={0};
        int pathVis[V]={0};
        int ans[V]={0};
        for(int i=0;i<V;i++){
            dfs(i,V,adj,vis,pathVis,ans);
        }
        vector<int>res;
        for(int i=0;i<V;i++)
        {
            if(ans[i]==1)
            res.push_back(i);
        }
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends