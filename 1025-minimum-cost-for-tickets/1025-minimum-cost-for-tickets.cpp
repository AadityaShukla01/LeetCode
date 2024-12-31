class Solution {
public:
    int dp[366];
    int sol(int day, vector<int>&costs, int end, map<int, int>&mp)
    {
        if(day > end) return 0;
        if(dp[day] != -1)
            return dp[day];
        int ans = 1e9;

        if(!mp[day]) ans = sol(day + 1, costs, end, mp);

        int one = sol(day + 1, costs, end, mp) + costs[0];
        int seven = sol(day + 7, costs, end, mp) + costs[1];
        int thirty = sol(day + 30, costs, end, mp) + costs[2];

        ans = min({ans, one, seven, thirty});

        return dp[day] = ans;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        map<int, int>mp;
        for(auto el: days)
            mp[el]++;

        int n = days.size();
        memset(dp, -1, sizeof(dp));
        return sol(0, costs, days[n - 1], mp);
    }
};