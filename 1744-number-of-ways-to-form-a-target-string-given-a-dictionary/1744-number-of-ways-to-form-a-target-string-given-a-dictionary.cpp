class Solution {
public:
    const int mo = 1e9 + 7;

    int dp[1001][1002];
    int m;
    int sol(int i, int j, int n, string& target, map<int, map<char, int>> &mp) {
        if (i >= n)
            return 1;
        
        if(j >= m)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        long long ans = 0;

        char c = target[i];

        ans += sol(i, j + 1, n, target, mp);
        
        if(mp[j].find(c) != mp[j].end()){
            long long steps = 1LL * sol(i + 1, j + 1, n, target, mp) * mp[j][c];
            steps %= mo;
            ans += steps;
            ans %= mo;
        }

        return dp[i][j] = ans % mo;
    }
    int numWays(vector<string>& words, string target) {
        map<int, map<char, int>> mp;
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < words.size(); i++) {
            m = words[i].size();
            for (int j = 0; j < words[i].size(); j++) {
                mp[j][words[i][j]]++;
            }
        }
        int n = target.size();
        return sol(0, 0, n, target, mp);
    }
};