//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> ans(V);
        for(int i=0;i<V;i++){
            ans[i]=1e9;
        }
        
        //inserting intial values
        ans[S]=0;
        set<pair<int,int>>set;
        set.insert({0,S});
        
        while(set.empty()==false){
            //iterator pointing to top element of set
            auto it=*(set.begin());
            int wt=it.first;
            int node=it.second;
            set.erase(it);
            //travelling and calculating distance from its neighbours
            for(auto i:adj[node]){
                int n=i[0];
                int edgeWeight=i[1];
                
                if(ans[n]>wt+edgeWeight){
                    if(ans[n]!=-1e9) // it means someone elese already travelled it
                        set.erase({ans[n],n}); //erase it no need to travel it
                    ans[n]=wt+edgeWeight;
                    set.insert({edgeWeight+wt,n});
            }
        }
    }
        return ans;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends