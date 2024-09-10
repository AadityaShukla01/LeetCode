class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();

        long long total = 1LL*n * (n + 1)/2;

        map<char, int>mp;
        int j = 0;
        long long bad = 0;
        for(int i=0; i<n; i++)
        {
            mp[s[i]]++;

            if(mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0){
                while(mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0)
                {
                    mp[s[j]]--;
                    j++;
                }
            }
            // cout << (i - j + 1) << "\n";
            bad += (i - j + 1);
        }
        return total - bad;
    }
};