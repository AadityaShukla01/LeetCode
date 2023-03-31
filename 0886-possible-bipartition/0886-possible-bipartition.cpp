class Solution {
public:
    bool sol(int n,vector<int>adj[],vector<int>&color){
        queue<int>q;
        q.push(n);
        int col=0;
        color[n]=col;
        
        while(q.empty()==false){
            int node=q.front();
            q.pop();

            for(auto it:adj[node]){
                if(color[it]==color[node]) return false;
                if(color[it]==-1){
                    color[it]=!color[node];
                    q.push(it);
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& g) {
        vector<int>adj[n+1];

        for(auto it:g){
            int a=it[0];
            int b=it[1];

            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<int>color(n+1,-1);
        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                if(sol(i,adj,color)==false) return false;
            }
        }
        return true;
    }
};