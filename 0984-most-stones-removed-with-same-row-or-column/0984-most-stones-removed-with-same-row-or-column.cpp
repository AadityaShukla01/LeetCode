class Solution {
public:
    void sol(int i, vector<vector<int>>& stones, vector<int>&vis){
        int n = stones.size();

        for(int j=0; j<n; j++){
            if(vis[j] || i == j) continue;

            if(stones[j][0] == stones[i][0] || stones[j][1] == stones[i][1]){
                vis[j] = 1;
                sol(j, stones, vis);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        // all stones in either same row or same col form a group
        // 1 element will always be left unpaired in a group
        // ans = n - total number of groups(left/remanig)

        vector<int>vis(n, 0);
        int group = 0;
        for(int i=0; i<n; i++){
            if(vis[i] == 0){
                group++;
                sol(i, stones, vis);
            }
        }
        return n - group;
    }
};