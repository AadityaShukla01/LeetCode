//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool cycle(int src ,vector<int> adj[],int vis[]){
        //make current node visited
        vis[src]=1;
        queue<pair<int,int>>q;
        q.push({src,-1});
        
        while(q.empty()==false){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            
            for(auto n:adj[node])
            {
                if(vis[n]==0){
                    vis[n]=1;
                    //node and parent from which it came
                    q.push({n,node});
                }
                else{
                    if(n!=parent) return true;
                }
            }
        }
        return false;
    }
    
    bool dfs(int node,int parent,vector<int> adj[],int vis[]){
        vis[node]=1;
        for(auto ele:adj[node]){
            if(vis[ele]==0) {
                if(dfs(ele,node,adj,vis)) return true;
            }
            else
            if(parent!=ele) return true;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V]={0};
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                if(dfs(i,-1,adj,vis)) return true;
            }
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