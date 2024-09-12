class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int n = allowed.size();
        int ms = 0;
        for(int i=0; i<n; i++)
        {
            ms = ms | (1 << (allowed[i] - 'a'));
        }

        int cnt = 0;

        for(auto s: words)
        {
            int nms = 0;
            for(auto c: s) nms = nms | (1 << (c - 'a'));

            if((nms & ms) == nms) cnt++;
        }
        return cnt;
    }
};