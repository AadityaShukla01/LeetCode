class Solution {
public:
    int dp[201][201];
    int sol(int i, int n, int j, vector<vector<int>>& triangle){
        if(i == n || j >= triangle[i].size()) return 1e9;
        // int ans = 1e9;
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans = 0;
        int a1 = sol(i+1, n, j, triangle) + triangle[i][j];
        int a2 = sol(i+1, n, j+1, triangle) + triangle[i][j];

        ans += min(a1, a2);
        return dp[i][j] = ans;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        memset(dp, -1, sizeof(dp));
        return sol(0, n, 0, triangle) - 1e9;
    }
};