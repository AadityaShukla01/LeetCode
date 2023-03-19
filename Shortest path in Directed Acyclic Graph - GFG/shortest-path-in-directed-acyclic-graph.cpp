//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void dfs(int src,stack<int>&st,int vis[],vector<pair<int,int>>adj[]){
        vis[src]=1;
        
        for(auto it:adj[src]){
            int u=it.first;
            
            dfs(u,st,vis,adj);
        }
        //after its dfs call gets completed insert into stack
        //basically we are sorting according ot thoei finish time
        
        st.push(src);
    }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
       vector<pair<int,int>>adj[N];
       
       for(auto it:edges){
           int u=it[0];
           int v=it[1];
           int wt=it[2];
           
           adj[u].push_back({v,wt});
       }
       vector<int>dist(N,1e9);
       vector<int>ans(N,-1);
       stack<int>st;
       int vis[N]={0};
       for (int i = 0; i < N; i++) {
        if (!vis[i]) {
          dfs(i,st, vis,adj);
        }
      }
       dist[0]=0;
       while(st.empty()==false){
           int src=st.top();
           st.pop();
           
           //relaxation of neighbours
           
           for(auto it:adj[src]){
               int u=it.first;
               int wt=it.second;
               if(dist[src]+wt<dist[u]) dist[u]=dist[src]+wt;
           }
       }
       for(int i=0;i<N;i++){
           if(dist[i]!=1e9){
               ans[i]=dist[i];
           }
           
       }
       return ans;
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