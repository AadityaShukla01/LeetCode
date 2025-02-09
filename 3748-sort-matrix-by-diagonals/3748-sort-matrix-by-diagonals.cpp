class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();

        map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mp[i - j].push_back(g[i][j]);
            }
        }

        vector<vector<int>> res = g;
        int l = -1 * n + 1;
        for (l; l < n; l++) {
            if (l >= 0)
                sort(mp[l].begin(), mp[l].end(), greater<int>());
            else
                sort(mp[l].begin(), mp[l].end());
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = *(mp[i - j].begin());
                mp[i - j].erase(mp[i - j].begin());
            }
        }
        return res;
    }
};