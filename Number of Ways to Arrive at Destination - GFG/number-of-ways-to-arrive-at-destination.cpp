//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        //create adjancenncy list
        vector<pair<int,int>>adj[n];
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        vector<int>distance(n,1e9);
        vector<int>ways(n,0);
        
        distance[0]=0;
        ways[0]=1;
        
        q.push({0,0});
        
        while(q.empty()==false){
            auto it=q.top();
            int dist=it.first;
            int node=it.second;
            q.pop();
            for(auto it:adj[node]){
                int neighbour=it.first;
                int cost=it.second;
                
                if(dist+cost<distance[neighbour]){
                    distance[neighbour]=dist+cost;
                    q.push({distance[neighbour],neighbour});
                    ways[neighbour]=ways[node];
                    
                }
                else if(dist+cost == distance[neighbour]){
                    ways[neighbour]=ways[neighbour]+ways[node];
                }
            }
        }
        return ways[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends