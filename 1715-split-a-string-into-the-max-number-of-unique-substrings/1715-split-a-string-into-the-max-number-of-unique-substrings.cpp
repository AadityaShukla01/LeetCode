class Solution {
public:
    int ans;
    void sol(int i, int n, string &s, int &cnt, map<string, int>&mp)
    {
        if(i >= n)
        {
            if(cnt == mp.size())
                ans = max(ans, cnt);

            return;
        }

        for(int j=i; j<n; j++)
        {
            string res = s.substr(i, j - i + 1);

            mp[res]++;
            cnt++;
            sol(j + 1, n, s, cnt, mp);
            cnt--;
            mp[res]--;
            if(mp[res] == 0) mp.erase(res);
        }
    }
    int maxUniqueSplit(string s) {
        ans = 0;
        int n = s.size();
        map<string, int>mp;
        int cnt = 0;
        sol(0, n, s, cnt, mp);
        return ans;
    }
};