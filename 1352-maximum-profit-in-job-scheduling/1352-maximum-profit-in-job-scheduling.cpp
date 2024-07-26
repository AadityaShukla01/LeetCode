class Solution {
public:
    // static bool comp(vector<int>&a, vector<int>&b){
    //     if(a[1] == b[1]) return a[0] < b[0];
    //     return a[1] < b[1];
    // }
    int dp[100001];
    int findIndex(int i, int en, vector<vector<int>>&v){
        int l = i;
        int h = v.size() - 1;
        int ans = h + 1; 
        while(l <= h){
            int m = l + (h - l)/2;

            if(v[m][0] >= en){
                ans = m;
                h = m - 1;
            } else l = m + 1;
        }
        return ans;
    }
    int sol(int i, int n, vector<vector<int>>&v){
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        int nextIndex = findIndex(i, v[i][1], v);

        int np = sol(i+1, n, v);
        int p = sol(nextIndex, n, v) + v[i][2];

        return dp[i] = max(p, np);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>>v;
        int n = profit.size();
        for(int i=0; i<n; i++){
            v.push_back({startTime[i], endTime[i], profit[i]});
        }
        memset(dp, -1, sizeof(dp));
        sort(v.begin(), v.end());

        return sol(0, n, v);
    }
};