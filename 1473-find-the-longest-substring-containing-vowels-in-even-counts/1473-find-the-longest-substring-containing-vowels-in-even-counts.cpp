class Solution {
public:
    bool isVowel(char c)
    {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
        return false;
    }
    int findTheLongestSubstring(string s) {
        int n = s.size();
        int mask = 0;

        map<int, int>mp;
        int maxLen = 0;
        mp[0] = -1;
        
        for(int i=0; i<n; i++)
        {
            // if same mask found earlier it means that in that particular range
            // every vowel occurs even amount of times
            // eg in mp[mask] = j for an index i it means that every char from [j + 1 to i]
            // will be present even number of times
            if(isVowel(s[i]))
                mask = mask ^ (1 << (s[i] - 'a'));

            if(mp.find(mask) != mp.end())
            {
                maxLen = max(maxLen, i - mp[mask]);
            }
            else
            {
                mp[mask] = i;
            }
        }
        return maxLen;
    }
};