class Solution {
public:
    bool isVowel(char c) {
        vector<char> v = {'a', 'e', 'i', 'o', 'u'};

        for (auto el : v) {
            if (c == el)
                return true;
        }
        return false;
    }
    long long countOfSubstrings(string s, int k) {
        int n = s.size();
        vector<int>pre(n, 0);
        pre[0] = !isVowel(s[0]);
        for(int i=1; i<n; i++)
        {
            if(isVowel(s[i])) pre[i] = pre[i - 1];
            else pre[i] = pre[i - 1] + 1;
        }

        int i = 0, j = 0;
        map<char, int>mp;
        long long ans = 0;
        int cnt = 0;
        
        while(i < n && j < n)
        {   
            if(isVowel(s[i]))
                mp[s[i]]++;
            else cnt++;

            // bad window -> shrink
            if(cnt > k)
            {
                while(cnt > k){
                    if(isVowel(s[j]))
                    {
                        mp[s[j]]--;
                        if(mp[s[j]] == 0) mp.erase(s[j]);
                    }
                    else cnt--;
                    
                    
                    j++;
                }
            }
            // count all valid substrings(i--------ub)
            // ub because we are finding range where this subarray has exactly k constants
            int ub = -1;
            while(cnt == k && mp.size() == 5)
            {
                // find index of next consonant;
                if(ub == -1)
                    ub = upper_bound(pre.begin(), pre.end(), pre[i]) - pre.begin();

                ans += (ub - i);

                if(isVowel(s[j]))
                {
                    mp[s[j]]--;
                    if(mp[s[j]] == 0) mp.erase(s[j]);
                }
                else cnt--;
                j++;
            }
            i++;
        }
        return ans;
    }
};