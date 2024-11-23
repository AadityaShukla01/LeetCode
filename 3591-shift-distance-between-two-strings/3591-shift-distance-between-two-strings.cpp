class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost,
                            vector<int>& previousCost) {
        vector<vector<long long>> v(26, vector<long long>(26, 0));

        for (int i = 0; i < 26; i++) {
            long long c = 0;
            for (int j = i; j < 26; j++) {
                v[i][j] = c;
                c += nextCost[j];
            }
        }

        for (int i = 0; i < 26; i++) {
            long long c = 0;
            for (int j = i + 1; j < 26; j++) {
                c += previousCost[j];
                v[j][i] = c;
            }
        }

        long long ans = 0;
        for (int i = 0; i < s.size(); i++) {
            char c1 = s[i], c2 = t[i];
            if (c1 == c2)
                continue;

            long long cost1 = 0, cost2 = 0;

            if (s[i] < t[i]) {
                cost1 = v[c1 - 'a'][c2 - 'a'];
                cost2 = v[c1 - 'a'][0] + previousCost[0] + v[25][c2 - 'a'];

                ans += min(cost1, cost2);
            } else {
                cost1 = v[c1 - 'a'][c2 - 'a'];
                cost2 = v[c1 - 'a'][25] + nextCost[25] + v[0][c2 - 'a'];
                // int cost3 = v[c1 - 'a'][0] + nextCost[0] + v[25][c2 - 'a'];

                ans += min(cost1, cost2);
            }
        }

        return ans;
    }
};