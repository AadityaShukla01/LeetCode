class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& g) {
        int n = g.size();
        map<int, int>mp;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                mp[g[i][j]]++;
            }
        }
        int a, b;
        for(int i=1; i<=n*n; i++)
        {
            if(mp.find(i) == mp.end())    a = i;
            else if(mp[i] == 2)   b = i;
        }
        return {b, a};
    }
};