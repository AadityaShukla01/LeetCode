class Solution {
public:
    
    void dfs(int node,vector<int>adj[],long long &count,vector<int>&vis){
        vis[node]=1;
        count++;
        for(auto it:adj[node]){
            if(vis[it]==0)
                dfs(it,adj,count,vis);
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
     vector<int>adj[n];
     for(auto it:edges){
         int a=it[0];
         int b=it[1];

         adj[a].push_back(b);
         adj[b].push_back(a);
     }
     long long totalgoodPairs=(long long)n*(n-1)/2;
     vector<long long>ans;
     vector<int>vis(n,0);
     for(int i=0;i<n;i++){
        long long count=0;
        if(vis[i]==0){
            //jab bi har node/component ke liye info chaiye to call ke andar innitialise karo
            count=0;
            dfs(i,adj,count,vis);
            totalgoodPairs=totalgoodPairs-((count)*(count-1)/2);
         }
            ans.push_back(count);
            // cout<<count<<endl;
     }
    return totalgoodPairs;
    }
};