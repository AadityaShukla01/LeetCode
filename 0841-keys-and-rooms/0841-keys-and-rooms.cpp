class Solution {
public:
    int vis[1001];
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n =rooms.size();
        vector<int>adj[n];
        //create graph from input
        for(int i=0;i<n;i++){
            for(int j=0;j<rooms[i].size();j++){
                if(rooms[i].size() ==0) continue;
                    adj[i].push_back(rooms[i][j]);
            }
        }
        queue<int>q;
        q.push(0);
        vis[0] = 1;
        while(q.empty()==false){
            int node = q.front();
            q.pop();

            for(auto it : adj[node]){
                if(vis[it] == 0){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(vis[i] == 0)
                return false;
        }
        return true;
    }
};