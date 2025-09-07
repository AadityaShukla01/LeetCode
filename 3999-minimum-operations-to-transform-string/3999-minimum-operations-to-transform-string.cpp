class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        
        int mx = 0;
        for(auto c: s) {
            if(c == 'a') continue;
            mx = max(mx, 26 - (c - 'a'));
        }

        return mx;
    }
};