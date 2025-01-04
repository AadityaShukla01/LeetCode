class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<vector<int>> v(n + 1, vector<int>(26, 0));
        vector<int> vis(26, 0);

        int cnt = 0;

        map<char, pair<int, int>> mp;

        for (int i = 0; i < n; i++) {
            if (mp.find(s[i]) == mp.end())
                mp[s[i]].first = i;
            mp[s[i]].second = i;
        }
        for (int i = 0; i < 26; i++)
            v[0][i] = 0;
        for (int i = 1; i <= n; i++) {
            v[i] = v[i - 1];
            v[i][s[i - 1] - 'a'] = v[i - 1][s[i - 1] - 'a'] + 1;
        }
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (vis[c - 'a'])
                continue;
            int f = mp[c].first;
            int st = mp[c].second;
            vis[c - 'a'] = 1;

            for (int j = 0; j < 26; j++) {
                if (j == (c - 'a')) {

                    if (f) {
                        if (v[st + 1][j] - v[f][j] >= 3) {
                            // cout << "1-" << i << j << "\n";
                            cnt++;
                        }
                    } else {
                        if (v[st + 1][j] >= 3) {
                            // cout <<"2-" <<  i << j << "\n";

                            cnt++;
                        }
                    }
                } else {
                    if (f) {
                        if (v[st + 1][j] - v[f][j]) {
                            // cout <<"3-" <<  i << j << "\n";
                            cnt++;
                        }
                    } else {
                        if (v[st + 1][j]) {
                            // cout << "4-" << i << j << "\n";
                            cnt++;
                        }
                    }
                }
            }
        }
       
        return cnt;
    }
};
// 0 a a + b a + b + c