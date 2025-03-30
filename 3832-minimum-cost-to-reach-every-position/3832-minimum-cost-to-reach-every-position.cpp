class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        int n = cost.size();
        vector<int>ans(n);
        int mn = 1e9;
        for(int i=0; i<n; i++)
        {
            mn = min(mn, cost[i]);
            ans[i] = min(cost[i], mn);
        }
        return ans;
    }
};