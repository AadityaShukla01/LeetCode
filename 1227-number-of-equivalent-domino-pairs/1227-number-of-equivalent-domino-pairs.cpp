class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n = dominoes.size();
        vector<vector<int>> vis(10, vector<int>(10, 0));
        int count = 0;
        for (int i = 0; i < n; i++) {
            int a = dominoes[i][0];
            int b = dominoes[i][1];

            if (a != b) {
                count += vis[a][b];
            }
            count += vis[b][a];
            vis[a][b]++;
        }
        return count;
    }
};