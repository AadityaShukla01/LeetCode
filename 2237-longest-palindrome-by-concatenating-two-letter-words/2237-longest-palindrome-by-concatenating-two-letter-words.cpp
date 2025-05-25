class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n = words.size();
        map<string, int> mp;
        int cnt = 0;
        bool flag = 0;

        for (auto w : words) {
            if (w[0] == w[1]) {
                mp[w]++;
            } else if (w[0] != w[1]) {
                string temp = w;
                reverse(temp.begin(), temp.end());
                if (mp[temp]) {
                    cnt += 4;
                    mp[temp] -= 1;
                } else
                    mp[w]++;
            }
        }
        for (auto it : mp) {
            string s = it.first;
            int f = it.second;
            if (s[0] == s[1]) {
                if (f % 2 == 0)
                    cnt += 2 * f;
                else if (f % 2) {
                    flag = 1;
                    cnt += 2 * (f - 1);
                }
            }
        }
        return cnt + flag * 2;
    }
};