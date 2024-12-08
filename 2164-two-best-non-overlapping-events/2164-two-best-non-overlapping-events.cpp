class Solution {
public:
    int fn(vector<vector<int>>& events, int i, int n) {
        int lo = i + 1;
        int hi = n - 1;

        int ans = n;

        while (lo <= hi) {
            int mi = lo + (hi - lo) / 2;

            if (events[mi][0] > events[i][1]) {
                ans = mi;
                hi = mi - 1;
            } else
                lo = mi + 1;
        }
        return ans;
    }
    
    int sol(int i, int n, int t, vector<vector<int>>& events, vector<vector<int>>& dp) {
        if (t == 2 || i >= n)
            return 0;

        
        if (dp[i][t] != -1)
            return dp[i][t];

        int ans = -1e9;

        int np = sol(i + 1, n, t, events, dp);

        int val = events[i][2];

        int nextIndex = fn(events, i, n);

        int p = sol(nextIndex, n, t + 1, events, dp) + val;

        ans = max(p, np);

        return dp[i][t] = ans;
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end());
        vector<vector<int>>dp(n, vector<int>(3, -1));
        return sol(0, n, 0, events, dp);
    }
};