class Solution {
public:
    int sum;
    int c;
    void dfs(int node , vector<int>adj[],vector<int> &vis){
        vis[node] = 1;
        c++;
        sum+=adj[node].size();
        for(auto it : adj[node]){
            if(vis[it] == 0){
                dfs(it,adj,vis);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(auto it : edges){
            int u =it[0];
            int v =it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans=0;
        int res=0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                c=0,sum=0;
                dfs(i,adj,vis);
                cout<<c<<" "<<sum<<endl;
                int edges = sum/2;
                if(c*(c-1)/2 == edges)
                    res++;
    }
}
        return res;
    }
};