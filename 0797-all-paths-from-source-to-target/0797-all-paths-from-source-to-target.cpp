class Solution {
public:
    int n;
    vector<vector<int>> ans;
    void dfs(int node,vector<vector<int>>& graph,vector<int>path){
        path.push_back(node);
        //dfs traversal
        if(node==n-1){
            ans.push_back(path);
            return ;
        }
        for(auto it:graph[node]){
                dfs(it,graph,path);
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int>path;
        n=graph.size();
        dfs(0,graph,path);
        return ans;
    }
};