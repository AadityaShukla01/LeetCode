class Solution {
public:
    int calcPref(string& a, string& b) {
        int n = min(a.size(), b.size());

        int cnt = 0, i = 0;
        while (i < n && a[i] == b[i]) {
            cnt++;
            i++;
        }
        return cnt;
    }
    vector<int> longestCommonPrefix(vector<string>& words) {
        int n = words.size();

        vector<int> pref(n, 0);
        for (int i = 0; i < n-1; i++) {
            pref[i] = calcPref(words[i], words[i + 1]);
        }

        vector<int> left(n, 0), ryt(n, 0);
        left[0] = pref[0];
        for (int i = 1; i < n; i++) {
            left[i] = max(left[i - 1], pref[i]);
        }
        ryt[n - 1] = pref[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            ryt[i] = max(ryt[i + 1], pref[i]);
        }

        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            int l = 0;
            if (i - 2 >= 0)
                l = left[i - 2];
            int r = 0;
            if (i + 1 < n)
                r = ryt[i + 1];
            int curr = 0;
            if (i - 1 >= 0 && i + 1 < n) {
                curr = calcPref(words[i - 1], words[i + 1]);
            }

            ans[i] = max({l, r, curr});
        }
        return ans;
    }
};