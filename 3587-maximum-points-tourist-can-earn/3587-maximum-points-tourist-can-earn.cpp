class Solution {
public:
    int dp[201][201];
    int sol(int i, int n, int k, int pre, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore)
    {
        if(i >= k) return 0;

        if(dp[i][pre] != -1)
            return dp[i][pre];

        int ans = -1e9;

        for(int j=0; j<n; j++)
        {
            if(j != pre){

                int steps = sol(i + 1, n, k, j, stayScore, travelScore) + travelScore[pre][j];
                ans = max(ans, steps);
            }
        }

        ans = max(ans, sol(i + 1, n, k, pre, stayScore, travelScore) + stayScore[i][pre]);

        return dp[i][pre] = ans;
    }
    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        int a = INT_MIN;
        memset(dp, -1, sizeof(dp));
        for(int i=0; i<n; i++){
            a = max(a, sol(0, n, k, i, stayScore, travelScore));
        }
        return a;
    }
};