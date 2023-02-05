//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Code here
        //create a disance array
        vector<int>distance(V,1e8);
        distance[S]=0; //source node
        
        //we will be iterating n-1 times
        for(int i=0;i<V-1;i++){
            //check neighbour via adjacency list
            for(auto it:edges){
                int u=it[0];
                int v=it[1];
                int cost=it[2];
                
                if(distance[u]!=1e8 ){
                    if(distance[u]+cost<distance[v]){
                        distance[v]=distance[u]+cost;
                    }
                }
            }
        }
        //check for nth time for - cycles
        for(auto it:edges){
            int u=it[0];
                int v=it[1];
                int cost=it[2];
                
                if(distance[u]!=1e8 ){
                    if(distance[u]+cost<distance[v]){
                        // distance[v]=distance[u]+cost;
                        return {-1}; //for - cycles
                    }
                }
        }
        return distance;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends