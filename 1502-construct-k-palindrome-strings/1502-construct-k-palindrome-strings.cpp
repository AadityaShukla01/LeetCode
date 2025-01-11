class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();
        if(n < k) return false;
        int cnt = 0;
        map<char, int>mp;
        for(auto c: s) mp[c]++;
        for(auto it: mp){
            if(it.second % 2) cnt++;
        }
        return cnt <= k;
    }
};