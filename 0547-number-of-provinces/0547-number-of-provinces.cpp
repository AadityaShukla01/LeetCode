class Solution {
public:
    void dfs(int node,vector<int>adjList[],int visited[]){
        visited[node]=1;
        for(auto padosi:adjList[node]){
            if(!visited[padosi]){
                dfs(padosi,adjList,visited);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        //preparing list from matrix
        int maa=0;
        vector<int>adjList[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
               if(isConnected[i][j]==1 && i!=j){
                   adjList[i].push_back(j);
                   adjList[j].push_back(j);
               }
                
            }
        }
        int visited[101]={0};
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                maa++;
                dfs(i,adjList,visited);
            }
        }
        return maa;
    }
};