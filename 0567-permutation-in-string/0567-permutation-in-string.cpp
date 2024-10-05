class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        int cnt = s1.size();
        map<char, int>mp;
        for(auto c: s1) mp[c]++;

        int i = 0, j = 0;

        while(i < m)
        {
            if(mp[s2[i]])
                cnt--;
            mp[s2[i]]--;

            if(cnt == 0)
            {
                int len = i - j + 1;
                while(cnt == 0)
                {
                    mp[s2[j]]++;
                    if(mp[s2[j]]) cnt++;
                    len = min(len, i - j + 1);
                    j++;
                }
                if(len == n) return true;
            }
            i++;
        }
        return false;
    }
};