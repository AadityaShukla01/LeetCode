class Solution {
public:
    void count(int node ,vector<int>adj[],vector<int> &vis){
        queue<int>q;
        // int n = isConnected.size();
        q.push(node);
        vis[node]= 1;
        while(q.empty()==false){
            int n=q.front();
            q.pop();
            for(auto i:adj[n]){
                if(vis[i] == 0){
                    vis[i] = 1;
                    q.push(i);
                }
            }
        }   
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int c = 0;
        queue<int>q;
        int n = isConnected.size();
        vector<int>adj[n+1];
        vector<int>vis(n+1,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<isConnected[0].size();j++){
                if(isConnected[i][j] && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                c++;
                count(i,adj,vis);
            }
        }
        return c;
    }
};