class Solution {
public:
    static bool cmp(const vector<int>&a, const vector<int>&b)
    {
        if(a[1] == b[1])
            return a[0] < b[0];
        return a[1] < b[1];
    }
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<int>ans(n, 0);

        map<int, vector<vector<int>>>mp;

        for(int i=0; i<n; i++)
        {
            mp[times[i][0]].push_back({i, 1});
            mp[times[i][1]].push_back({i, -1});
        }

        set<int>busy;
        set<int>free;
        for(int i=0; i<n; i++) free.insert(i);
        for(auto it: mp)
        {
            vector<vector<int>>t = it.second;

            sort(t.begin(), t.end(), cmp);
            for(auto v: t)
            {
                if(v[1] == 1)
                {
                    ans[v[0]] = *free.begin();
                    free.erase(free.begin());
                }
                else
                    free.insert(ans[v[0]]);
            }
        }

        return ans[targetFriend];
    }
};