class Solution {
public:
    int dp[501][501][3];
    int sol(int i, int j, int n, int m, vector<vector<int>>&coins, int cnt){
        if(i == n - 1 && j == m - 1){
            if(coins[i][j] >= 0) return coins[i][j];
            else if(cnt) return 0;
            else return coins[i][j];
        }

        if(i >= n) return -1e9;

        if(j >= m) return -1e9;


        if(dp[i][j][cnt] != -1)
            return dp[i][j][cnt];

        int ans = -1e9;
        if(coins[i][j] >= 0){
            int op1 = sol(i + 1, j, n, m, coins, cnt) + coins[i][j];
            int op2 = sol(i, j + 1, n, m, coins, cnt) + coins[i][j];
            ans = max({ans, op1, op2});
        }
        else{
            int op1 = sol(i + 1, j, n, m, coins, cnt) + coins[i][j];
            int op2 = sol(i, j + 1, n, m, coins, cnt) + coins[i][j];
            int op3 = -1e9, op4 = -1e9;
            if(cnt){
                op3 = sol(i + 1, j, n, m, coins, cnt - 1);
                op4 = sol(i, j + 1, n, m, coins, cnt - 1);
            }
            ans = max({ans, op1, op2, op3, op4});
        }
        return dp[i][j][cnt] = ans;
    }
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size(), m = coins[0].size();
        memset(dp, -1, sizeof(dp));
        return sol(0, 0, n, m, coins, 2);
    }
};