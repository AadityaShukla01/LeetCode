class Solution {
public:
    int minChanges(string s) {
        int n = s.size();
        int i = 0, j = 0;
        map<int, int>mp;
        int cnt = 0;
        int len = 0;
        while(i < n)
        {
            mp[s[i]]++;
            len++;
            if(len % 2 == 0 && mp.size() == 1)
            {
                len = 0;
                mp.clear();
            }
            else if(len % 2 == 0 && mp.size() == 2)
            {
                cnt += min(mp['0'], mp['1']);
                mp.clear();
                len = 0;
            }
            i++;
        }
        return cnt;
    }
};