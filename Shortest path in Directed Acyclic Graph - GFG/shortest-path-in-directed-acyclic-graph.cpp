//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  void sol(int node,vector<pair<int,int>>adj[],int vis[],stack<int>&st){
      vis[node]=1;
      for(auto it:adj[node]){
          int i=it.first;
          if(!vis[i]){
              sol(i,adj,vis,st);
          }
      }
      st.push(node);
  }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        stack<int>st;
        vector<pair<int,int>>adj[N];
        for(int i=0;i<edges.size();i++){
            int a=edges[i][0];
            int b=edges[i][1];
            int c=edges[i][2];
            
            adj[a].push_back({b,c});
        }
        int vis[N]={0};
        for(int i=0;i<N;i++){
            if(!vis[i]){
                sol(i,adj,vis,st);
            }
        }
        vector<int>dist(N,1e9);
        dist[0]=0;
        
        //calculate min distance and update the distance
        
        while(st.empty()==false){
            int a=st.top();
            st.pop();
            
            for(auto it:adj[a]){
                int f=it.first;
                int s=it.second;
                if(dist[a]+s<dist[f]){
                    dist[f]=dist[a]+s;
                }
            }
        }
        for(int i=0;i<N;i++)
        if(dist[i]==1e9)
        dist[i]=-1;
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends