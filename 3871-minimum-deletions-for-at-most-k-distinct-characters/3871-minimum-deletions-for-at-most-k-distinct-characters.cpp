class Solution {
public:
    int minDeletion(string s, int k) {
        int n = s.size();
        map<char, int>mp;
        for(auto c: s) mp[c]++;
        vector<int>f;
        for(auto it: mp) f.push_back(it.second);
        sort(f.begin(), f.end());
        if(f.size() <= k) return 0;
        int cnt = 0;
        int sz = 0;
        for(auto it: f){
            cnt += it;
            sz++;
            if(f.size() - sz <= k) return cnt;
        }
        return cnt;
    }
};