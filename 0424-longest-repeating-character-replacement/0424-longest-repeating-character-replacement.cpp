class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int i = 0, j = 0;
        map<char, int> mp;
        int maxF = 0;
        int ans = 0;
        while (i < n) {
            mp[s[i]]++;
            maxF = max(maxF, mp[s[i]]);
            int len = i - j + 1;
            if (len - maxF > k) {
                while (len - maxF > k) {
                    mp[s[j]]--;
                    len--;
                    maxF = 0;
                    for (char c = 'A'; c <= 'Z'; c++) {
                        maxF = max(maxF, mp[c]);
                    }
                    j++;
                }
            }

            ans = max(ans, i - j + 1);
            i++;
        }
        return ans;
    }
};