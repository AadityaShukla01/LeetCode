class Solution {
public:
    int dp[7][1001];
    bool sol(int i, string& s, int n, int sum) {

        if (i >= n)
            return sum == 0;

        if (dp[i][sum] != -1)
            return dp[i][sum];

        bool ans = false;

        for (int j = i; j < n; j++) {
            string res = s.substr(i, j - i + 1);
            if (sum >= stoi(res))
                ans |= sol(j + 1, s, n, sum - stoi(res));
        }
        return dp[i][sum] = ans;
    }
    int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            memset(dp, -1, sizeof(dp));
            string s = to_string(i * i);
            int len = s.size();
            if (sol(0, s, len, i))
                ans += i * i;
        }
        return ans;
    }
};