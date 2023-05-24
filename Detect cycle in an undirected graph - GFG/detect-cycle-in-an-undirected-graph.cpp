//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool sol(int node , int parent , vector<int>adj[],vector<int>vis){
        vis[node] =1;
        
        queue<pair<int,int>>q;
        q.push({node,parent});
        
        while(!q.empty()){
            int n = q.front().first;
            int parentNode = q.front().second;
            q.pop();
            
            for(auto i: adj[n]){
                if(vis[i] == 0){
                    vis[i] =1;
                    q.push({i,n});
                }
                else if(i != parentNode){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
            if(sol(i,-1,adj,vis))
                return true;
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends