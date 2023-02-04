//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        
        
        //creat adjacenecy list
        vector<int>adj[N];
        
        for(int i=0;i<edges.size();i++){
            int a=edges[i][0];
            int b=edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        queue<int>q;
        q.push(src);
        vector<int>ans(N,1e9);
        ans[src]=0;
        int vis[N]={0};
        while(q.empty()==false){
            int n=q.front();
            q.pop();
            for(auto i:adj[n]){
                //calculate min distance from source node

                if(ans[n]+1<ans[i]){
                    ans[i]=ans[n]+1;
                    q.push(i);
                }
            }
        }
        for(int i=0;i<ans.size();i++){
            if(ans[i]==1e9)
            ans[i]=-1;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends