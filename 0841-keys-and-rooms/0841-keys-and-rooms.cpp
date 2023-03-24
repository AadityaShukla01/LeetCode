class Solution {
public:
    int vis[10001];
    void dfs(int node,vector<vector<int>>& rooms){
        vis[node]=1;
        for(int i=0;i<rooms[node].size();i++){
            if(!vis[rooms[node][i]])
                dfs(rooms[node][i],rooms);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        int count=0;
    
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                dfs(i,rooms);
                count++;
            }
        }
        if(count==1) return true;

        return false;
    }
};