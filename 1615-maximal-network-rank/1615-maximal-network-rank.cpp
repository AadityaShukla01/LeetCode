class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int sum =0;
        vector<vector<int>>matrix(n,vector<int>(n,0));
        vector<int> indegree(n,0);
        for(auto it : roads){
            int u = it[0];
            int v = it[1];

            indegree[u]++;
            indegree[v]++;
            matrix[u][v]=1;
            matrix[v][u]=1;
        }
        int maxi=0;
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(matrix[i][j]){
                    ans=max(ans,indegree[i]+indegree[j]-1);
                }
                else{
                    ans=max(ans,indegree[i]+indegree[j]);
                }
            }
        }
    return ans;
    }
};