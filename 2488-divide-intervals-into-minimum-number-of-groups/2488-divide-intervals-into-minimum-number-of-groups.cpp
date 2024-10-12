class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int mx = 1;
        int cnt = 0;
        map<int, int>mp;

        for(auto it: intervals)
        {
            int a = it[0], b = it[1];

            mp[a]++;
            mp[b + 1]--;
        }

        for(auto it: mp)
        {
            cnt += it.second;

            mx = max(mx, cnt);
        }
        return mx;
    }
};