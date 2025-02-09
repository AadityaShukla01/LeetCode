class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        int n = groups.size(), m = elements.size();
        map<int, int> mp1;

        for (int i = 0; i < m; i++) {
            if (mp1.find(elements[i]) == mp1.end())
                mp1[elements[i]] = i;
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int el = groups[i];
            int mn = INT_MAX;
            for (int j = 1; j * j <= el; j++) {
                if (el % j == 0) {
                    if(mp1.find(j) != mp1.end())
                        mn = min(mn, mp1[j]);
                    if (el % (el / j) == 0 && mp1.find(el / j) != mp1.end())
                        mn = min(mn, mp1[el / j]);
                }
            }

            if (mn == INT_MAX)
                ans[i] = -1;
            else
                ans[i] = mn;
        }

        return ans;
    }
};