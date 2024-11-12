class Solution {
public:
    int sol(map<int, int>&mp, int q)
    {
        vector<int>v;
        for(auto it: mp) v.push_back(it.first);

        int ub = upper_bound(v.begin(), v.end(), q) 
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = queries.size();
        vector<int>ans(n);

        
        sort(items.begin(), items.end());

        map<int, int>mp;
        int mx = 0;
        for(auto it: items)
        {
            mx = max(mx, it.second);
            mp[it.first] = mx;
        }

        for(auto q: queries)
        {
            if(mp.find(q) != mp.end())
                ans.push_back(mp[q]);
            else
            {

            }
        }
    }
};