class Solution {
public:
    int largestCombination(vector<int>& c) {
        map<int, int>mp;
        int n = c.size();
        for(int i=0; i<32; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(c[j] & (1 << i))
                    mp[i]++;
            }
        }

        int mx = 0;

        for(auto it: mp)
        {
            mx = max(mx, it.second);
        }
        return mx;
    }
};