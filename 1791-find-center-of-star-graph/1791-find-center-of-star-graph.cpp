class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int>indegree(n+2,0);

        for(auto it : edges){
            int u = it[0];
            int v = it[1];

            indegree[u]++;
            indegree[v]++;
        }
        int ans = -1;
        for(int i = 0;i<n+2;i++){
            if(indegree[i] == n){
                ans= i;
            }
        }
        return ans;
    }
};