class Solution {
public:
    int maxDifference(string s) {
        int mx_o = INT_MIN;
        int mn_e = INT_MAX;
        map<char, int>mp;
        for(auto c: s) mp[c]++;

        for(auto it: mp)
        {
            if(it.second % 2 == 0) {
                mn_e = min(mn_e, it.second);
                
            }
            else{
              mx_o = max(mx_o, it.second);
            }
        }

        return (mx_o - mn_e);
    }
};