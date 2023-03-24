class Solution {
public:
    int vis[10001];
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        vector<int>indegree(n,0);
        //we will collect all nodes with indegrre 0
        for(auto it:edges){
            int u=it[0];int v=it[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) ans.push_back(i);
        }
        return ans;
    }
};