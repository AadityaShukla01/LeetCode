class Solution {
public:
    int findJudge(int N, vector<vector<int>>& edges) {
       //creating adjacency list
        vector<int>indegree(N+1,0);
        vector<int>outdegree(N+1,0);
       for(auto it:edges){
           int u=it[0];
           int v=it[1];
           indegree[v]++;
           outdegree[u]++;
       }
        int maxi=0;
        int maxAns=0;

        for(int i=0;i<N+1;i++){
            if(indegree[i]>0 && outdegree[i]==0){
                maxAns=i;
                maxi=indegree[i];
            }
        }
        if(edges.size()==0 && N==1) return 1;
        if(edges.size()==0 && N>1) return -1;
        if(maxAns && maxi==N-1) return maxAns;
        return -1;
    }
};