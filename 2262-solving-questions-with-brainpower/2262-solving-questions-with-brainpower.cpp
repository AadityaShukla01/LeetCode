class Solution {
public:
    long long dp[100001];
    long long sol(int i, int n, vector<vector<int>>& questions)
    {
        if(i >= n) return 0;
        if(dp[i] != -1)
            return dp[i];

        int points = questions[i][0], brainpower = questions[i][1];
        long long p = sol(i + brainpower + 1, n, questions) + points;
        long long np = sol(i + 1, n, questions);

        return dp[i] = max(p, np);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        memset(dp, -1, sizeof(dp));
        return sol(0, n, questions);
    }
};