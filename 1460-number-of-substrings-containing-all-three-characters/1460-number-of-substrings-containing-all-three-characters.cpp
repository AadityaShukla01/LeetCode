class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int cnt = 0;
        int i = 0, j = 0;
        map<char, int>mp;
        while(i < n)
        {
            if(s[i] == 'a' || s[i] == 'b' || s[i] == 'c') {
                mp[s[i]]++;
            }

            if(mp.size() == 3)
            {
                while(mp.size() == 3)
                {
                    cnt += (n - i);
                    mp[s[j]]--;
                    if(mp[s[j]] == 0) mp.erase(s[j]);
                    j++;
                }
            }
            i++;
        }
        return cnt;
    }
};