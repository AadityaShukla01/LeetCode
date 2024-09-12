class Solution {
public:
    int mx;
    void sol(int i, int n, string &s, vector<string>&temp, set<string>&set)
    {
        if(i >= n) {
            int sz = temp.size();
            mx = max(mx, sz);
            return;
        }
        for(int j=i; j<n; j++)
        {
            string st = s.substr(i, j - i + 1);
            if(set.find(st) == set.end()){
                temp.push_back(st);
                set.insert(st);
                sol(j+1, n, s, temp, set);
                set.erase(st);
                temp.pop_back();
            }
        }
    }
    int maxUniqueSplit(string s) {
        int n = s.size();
        vector<string>temp;
        set<string>set;
        sol(0, n, s, temp, set);
        return mx;
    }
};