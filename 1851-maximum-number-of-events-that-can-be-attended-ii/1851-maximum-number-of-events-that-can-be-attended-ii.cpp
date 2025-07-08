class Solution {
public:
    int findIndex(int lo, int hi, vector<vector<int>>& events, int val){
        int ans = hi + 1;
        while(lo <= hi){
            int mi = lo + (hi - lo)/2;
            if(events[mi][0] > val){
                ans = mi;
                hi = mi - 1;
            }
            else lo = mi + 1;
        }
        return ans;
    }
    int sol(int i, int n, vector<vector<int>>& events, int k, vector<vector<int>>&dp){
        if(k == 0) return 0;
        if(i >= n) return 0;

        if(dp[i][k] != -1) return dp[i][k];

        int np = sol(i + 1, n, events, k, dp);

        int nextIndex = findIndex(i + 1, n - 1, events, events[i][1]);

        int p = sol(nextIndex, n, events, k - 1, dp) + events[i][2];

        return dp[i][k] = max(p, np); 
    }
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end()); 
        int sz = min(k, (1000000 / n));
        vector<vector<int>>dp(n, vector<int>(sz + 1, -1));
        return sol(0, n, events, sz, dp);
    }
};