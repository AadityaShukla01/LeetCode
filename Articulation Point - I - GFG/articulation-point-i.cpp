//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  int timer=0;//for starting point
  void dfs(int node,int parent,int vis[],int mark[],vector<int>adj[],int in[],int low[]){
      vis[node]=1;
      low[node]=in[node]=timer;
      timer++;
        int child=0;
      for(auto it:adj[node]){
          if(it==parent) continue;
          if(vis[it]==0){
              dfs(it,node,vis,mark,adj,in,low);
              //after dfs call we check update low and in time
              
              low[node]=min(low[it],low[node]);
              //checking for articulation point
              
              //checking if node can reach ancestor of adjacnt node we are writing
            //   equal condition because if we reach to adjacent node like bridges
            // here we ae cutting an entire node along with its edges so we must reach to
            //only acestor of the node
              if(low[it]>=in[node] && parent!=-1){
                  mark[node]=1;
              }
              child++; //to know no of nodes connected to strating node
              //if starting node has only 1 child it will not be a articulation point
              
          }
          else {
              low[node]=min(in[it],low[node]);
          }
      }
      if(child>1 && parent==-1) mark[node]=1;
  }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        int vis[V]={0};
        vector<int>ans;
        int low[V]={0};
        int in[V]={0};
        int mark[V]={0};
        
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                dfs(i,-1,vis,mark,adj,in,low);
            }
        }
        for(int i=0;i<V;i++){
            if(mark[i]==1){
                ans.push_back(i);
            }
        }
        
        if(ans.size()>0) return ans;
        return {-1};
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends