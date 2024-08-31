class Solution {
public:
    int dp[501][501];
    int sol(int i, int n, int rem, vector<int>&cost, vector<int>&time){
        if(rem <= 0) return 0;

        if(i >= n) return 1e9;

        if(dp[i][rem] != -1)
            return dp[i][rem];
        // rem - time[i] - 1 because in time[i] time free worker will work & -1 for the wall in whic we are currently
        int p = cost[i] + sol(i+1, n, rem - 1 - time[i], cost, time);

        int np = sol(i+1, n, rem, cost, time);

        return dp[i][rem] = min(np, p);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        memset(dp, -1, sizeof(dp));
        return sol(0, n, n, cost, time);
    }
};