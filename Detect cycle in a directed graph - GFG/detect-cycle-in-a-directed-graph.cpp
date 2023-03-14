//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int node,int V, vector<int> adj[],int  vis[],int pathVis[]){
        vis[node]=1;
        pathVis[node]=1;
        
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,V,adj,vis,pathVis)) return true;
            }
            else if(pathVis[it]==1) return true;
        }
        pathVis[node]=0;
        return false;
    }
    vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    int vis[V]={0};
	    vector<int>ans;
	    int indegree[V]={0};
	    
	    for(int i=0;i<V;i++){
	        for(auto it:adj[i]){
	            indegree[it]++;
	        }
	    }
	    
	    queue<int>q;
	    for(int i=0;i<V;i++){
	        
	        if(indegree[i]==0)  q.push(i);
	        
	    }
	   // /we only push the node if indegree is 0
	    while(q.empty()==false){
	        
	        int node=q.front();
	        q.pop();
	        ans.push_back(node);
	        
	        for(auto it:adj[node]){
	            
	            indegree[it]--;
	            if(indegree[it]==0)
	                q.push(it);
	                
	        }
	   }

        return ans;
	}
    bool isCyclic(int V, vector<int> adj[]) {
        // int pathVis[V]={0};
        // int vis[V]={0};
    
        
        // for(int i=0;i<V;i++){
        //     if(!vis[i]){
        //         if(dfs(i,V,adj,vis,pathVis)==true) return true;
        //     }
        // }
        // return false;
        vector<int>ans;
        ans=topoSort(V,adj);
        // cout<<ans.size();
        if(ans.size()!=V) return true;
        return false;
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
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends