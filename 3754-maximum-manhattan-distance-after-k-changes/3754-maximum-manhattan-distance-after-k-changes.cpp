class Solution {
public:
    // took help i might be finished fr
    int maxDistance(string s, int k) {
        map<char, int>mp;
        int mx = 0;
        int orig = k;
        for(auto c: s) {
            k = orig;
            mp[c]++;

            int cn = mp['N'];
            int cs = mp['S'];
            int ce = mp['E'];
            int cw = mp['W'];


            int c1 = min(cn, cs);

            int ans = 0;

            if(c1 <= k)
            {
                ans += cn + cs;
                k -= c1;
            }
            else
            {
                ans += max(cn, cs) + k - (c1 - k);
                k = 0;
            }


            int c2 = min(mp['E'], mp['W']);

            if(c2 <= k)
            {
                ans += ce + cw;
                
                k -= c1;
            }
            else
            {
                ans += max(cw, ce) + k - (c2 - k);
                
                k = 0;
            }
            mx = max(mx, ans);
        }
        return mx;
    }
};