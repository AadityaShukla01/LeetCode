class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        queue<int>q;
        q.push(k);
        vector<int>dist(n+1,INT_MAX);
        dist[0]=0;
        dist[k]=0;
        vector<vector<int>> adj[n+1];
        for(auto it:times){
            int u=it[0];
            int v=it[1];
            int wt=it[2];

            adj[u].push_back({v,wt});
        }
        while(q.empty()==false){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                int n=it[0];
                int wt=it[1];

                if(wt+dist[node]<dist[n]){
                    dist[n]=wt+dist[node];
                    q.push(n);
                }
            }
        }
        for(int i=0;i<=n;i++){
            cout<<dist[i]<<endl;
        }
        int a=*max_element(dist.begin(),dist.end());
        if(a==INT_MAX) return -1;
        return a;
    }
};