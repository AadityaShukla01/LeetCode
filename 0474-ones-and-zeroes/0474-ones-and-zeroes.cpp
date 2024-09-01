class Solution {
public:
    pair<int, int>count(string &s)
    {
        int o = 0, z = 0;
        for(auto c: s){
            if(c == '0') z++;
            else o++;
        }
        return {o, z};
    }
    int sol(int i, vector<string>&strs, int o, int z, int m, int n)
    {
        if(i >= strs.size()) return 0;

        int p = 0;
        pair<int, int>cnt = count(strs[i]);
        
        if(cnt.first + o <= n && cnt.second + z <= m){
            p = sol(i + 1, strs, cnt.first + o, cnt.second + z, m, n) + 1;
        }
        int np = sol(i + 1, strs, o, z, m, n);
        return max(p, np);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        return sol(0, strs, 0, 0, m, n);
    }
};