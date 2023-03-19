class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        //adjacency list
        int n=edges.size();
        vector<int>indegree(n+2,0);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            indegree[v]++;
            indegree[u]++;
        }
        int maxi=0;
        int maxAns=0;
        for(int i=0;i<n+2;i++){
            if(indegree[i]>maxi){
                maxAns=i;
                maxi=indegree[i];
            }
        }
        return maxAns;
    }
};