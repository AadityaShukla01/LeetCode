class Solution {
public:
    int dp[3001][3001];
    int sol(int i, int j, string &source, string &pattern, unordered_set<int>&set)
    {
        
        if(i >= source.size()) {
            if(j >= pattern.size()) return 0;

            return -1e9;
        }

        if(dp[i][j] != -1)
            return dp[i][j];

        int ans = -1e9;

        // if(j < pattern.size() && source[i] != pattern[j])
        ans = max(ans, sol(i + 1, j, source, pattern, set));

        if(set.find(i) != set.end())
        {
            ans = max(ans, sol(i + 1, j, source, pattern, set) + 1);
        }
        if(j < pattern.size() && source[i] == pattern[j])
        {
            ans = max(ans, sol(i + 1, j + 1, source, pattern, set));
        }

        return dp[i][j] = ans;
    }
    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
        int n = source.size();
        int m = pattern.size();
        unordered_set<int>set;
        for(auto el: targetIndices) set.insert(el);

        memset(dp, -1, sizeof(dp));

        return sol(0, 0, source, pattern, set);
    }
};