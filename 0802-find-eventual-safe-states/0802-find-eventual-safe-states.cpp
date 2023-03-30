class Solution {
public:
    //reverse edges and then do topo sort
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0), topo;
        for(int i = 0; i < n; ++i){
            for(auto &x : graph[i]){
                adj[x].push_back(i);    // [0->1,0->2] => [1->0,2->0]
            }
        }
        for(int i = 0; i < n; ++i){
            for(auto &x: adj[i]){
                indegree[x]++;
            }
        }
        queue<int> q;
        // for(auto &x : indegree){
        //     if(!x) q.push(x);
        // }
        for(int i = 0; i < n; i++) if(!indegree[i]) q.push(i);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto &adjnode: adj[node]){
                indegree[adjnode]--;
                if(!indegree[adjnode]) q.push(adjnode);
            }
        }
        sort(topo.begin(),topo.end());
        return topo;
    }
};