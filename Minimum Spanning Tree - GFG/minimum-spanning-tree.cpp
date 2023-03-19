//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet{
    vector<int> rank, parent,size;
    
    public:
        DisjointSet(int n){
            rank.resize(n+1,0);
            // size.resize(n+1,0)l//inintilazing our data structure
            parent.resize(n+1);
            
            for(int i=0;i<=n;i++)
                parent[i]=i; //initilaly it is parent of its own
        }
        
        int findParent(int node){
            if(parent[node]==node) return node; //base case reached the top taregt
            
            return parent[node]=findParent(parent[node]);
        }
        
        void unionByRank(int u, int v){
            int ultimateParentOfU=findParent(u);
            int ultimateParentOfV=findParent(v);
            
            //check if they are already belonging to same compoenent
            if(ultimateParentOfU==ultimateParentOfV)  return ;
            
            if(rank[ultimateParentOfV]<rank[ultimateParentOfU]){
                parent[ultimateParentOfV]=ultimateParentOfU;
            }
            else if(rank[ultimateParentOfV]>rank[ultimateParentOfU]){
                parent[ultimateParentOfU]=ultimateParentOfV;
            }
            else{
                parent[ultimateParentOfV]=ultimateParentOfU;
                rank[ultimateParentOfU]++;
            }
        }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<pair<int,pair<int,int>>>edges;
        int vis[V]={0};
        //since we are using disjoint datavstructure we dont need adjacency matrix
        // we just need u& v
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                int wt=it[1];
                int v=it[0];
            
            edges.push_back({wt,{i,v}});
        }
        }
        //wt //u v
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0,0});
        int sum=0;
        while(pq.empty()==false){
            int wt=pq.top().first;
            int u=pq.top().second;
            pq.pop();
            if(vis[u]==1) continue;
            
            vis[u]=1;
            sum+=wt;
            for(auto it:adj[u]){
                if(vis[it[0]]==0){
                    int n=it[0];
                    int cost=it[1];
                    pq.push({cost,n});
                }
            }
        }
        
    return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends