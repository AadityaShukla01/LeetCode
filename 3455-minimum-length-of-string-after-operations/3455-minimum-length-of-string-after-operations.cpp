class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        int cnt = 0;
        map<char, int> mp;
        for (auto c : s)
            mp[c]++;
        for (auto it : mp) {
            if (it.second % 2 == 0)
                cnt += 2;
            else
                cnt++;
        }
        return cnt;
    }
};