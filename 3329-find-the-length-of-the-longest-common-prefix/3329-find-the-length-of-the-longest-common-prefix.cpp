class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        map<string, int>mp;

        for(auto el: arr1)
        {
            string s = to_string(el);
            string res = "";
            for(auto c: s)
            {
                res += c;
                mp[res]++;
            }
        }

        int mx = 0;

        for(auto el: arr2)
        {
            string s = to_string(el);
            string res = "";
            for(auto c: s)
            {
                res += c;
                if(mp[res]){
                    int sz = res.size();
                    mx = max(mx, sz);
                }
            }
        }
        return mx;
    }
};