class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        map<char, int>mp;
        for(auto c: s) mp[c]++;
        
        if(mp['a'] < k || mp['b'] < k || mp['c'] < k)
            return -1;      

        int len = 0;
        int i = 0, j = 0;
        
        int req_a = mp['a'] - k;        
        int req_b = mp['b'] - k;
        int req_c = mp['c'] - k;

        mp.clear();
    
        while(i < s.size())
        {   
            mp[s[i]]++;

            if(mp['a'] > req_a || mp['b'] > req_b || mp['c'] > req_c)
            {
                while(mp['a'] > req_a || mp['b'] > req_b || mp['c'] > req_c)
                {
                    mp[s[j]]--;
                    j++;
                }
            }
            len = max(len, i - j + 1);
            i++;
        }
        return n - len;
    }
};