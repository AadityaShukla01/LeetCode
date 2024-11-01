class Solution {
public:
    // --------took help-----------
    
    long long dp[101][101][101];
    long long sol(int i, int j, int limit, vector<int>& robot, vector<vector<int>>& factory){
        if(i >= robot.size())
            return 0;

        if(j >= factory.size())
            return LLONG_MAX;

        if(dp[i][j][limit] != -1)
            return dp[i][j][limit];

        long long ans = 1e15;

        if(limit)
        {
            long long sum = abs(robot[i] - factory[j][0]);
            ans = min(ans, sol(i + 1, j, limit - 1, robot, factory) + sum);
        }

        if(j + 1 < factory.size())
            ans = min(ans, sol(i, j + 1, factory[j + 1][1], robot, factory));


        return dp[i][j][limit] = ans;
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        memset(dp, -1, sizeof(dp));

        return sol(0, 0, factory[0][1], robot, factory);
    }
};