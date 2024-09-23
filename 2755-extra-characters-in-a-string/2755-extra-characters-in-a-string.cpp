class Solution {
public:
    int m[51];
    int sol(int i, int n, string &s, map<string, int>&mp)
    {
        if(i >= n) return 0;
        if(m[i] != -1) return m[i];
        int ans = 1e9;
        for(int j=i; j<n; j++)
        {
            string res = s.substr(i, j - i + 1);
            if(mp[res] > 0)
            {
                ans = min(ans, sol(j + 1, n, s, mp));
            }
        }

        ans = min(ans, sol(i + 1, n, s, mp) + 1);

        return m[i] = ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        map<string, int>mp;
        memset(m, -1, sizeof(m));
        for(auto w: dictionary) mp[w]++;
        return sol(0, n, s, mp);
    }
};