class Solution {
public:
    const int mo = 1e9 + 7;
    int lengthAfterTransformations(string s, int t) {
        vector<long long>f(26, 0);

        for(auto c: s) f[c - 'a']++;
        int cnt = 0;
        for(int i=0; i<t; i++)
        {
            vector<long long>temp(26, 0);
            for(int j=0; j<26; j++)
            {
                if(j != 25)
                {
                    temp[j + 1] = f[j];
                }
                else
                {
                    temp[0] += f[25];
                    temp[1] += f[25];
                }
                temp[j] %= mo;
            }
            f = temp;
        }

        long long tot = 0;
        for(auto c: f) tot += c;
        tot %= mo;
        return tot;
    }
};