//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        
        //create adjancency list
        vector<pair<int,int>>a[n+1];
        for(auto it:edges){
            a[it[0]].push_back({it[1],it[2]});
            a[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,1});
        
        //create a distnce array to store min distance from source node
        //create a paren array to store the parent 
        
        vector<int>distance(n+1,1e9);
        vector<int>parent(n+1);
        for(int i=0;i<n+1;i++)
        parent[i]=i;
        
        distance[1]=0;
        vector<int>ans;
        
        //implement bfs
        while(pq.empty()==false){
            auto i=pq.top();
            int node=i.second;
            int dist=i.first;
            pq.pop();
            for(auto neig:a[node])
            {
                int adjNode=neig.first;
                int wt=neig.second;
                if(distance[adjNode]>wt+distance[node]){
                distance[adjNode]=wt+distance[node];
                
                pq.push({distance[adjNode],adjNode});
                parent[adjNode]=node;
                
            }
        }
        }
        int node=n;
        while(node!=parent[node]){
            ans.push_back(node);
            node=parent[node];
        }
        ans.push_back(1);
        reverse(ans.begin(),ans.end());
        
        if(distance[n]==1e9)
        return {-1};
        
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
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

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends