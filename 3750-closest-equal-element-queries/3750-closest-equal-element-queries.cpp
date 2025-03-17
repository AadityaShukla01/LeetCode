class Solution {
public:
    int sol(int index, int el, map<int, vector<int>>&mp, int len)
    {
        int n = mp[el].size();
        if(n == 1) return -1;

        int mn = 1e9;
        if(mp[el][0] == index)
        {
            mn = min(mn, mp[el][1] - index);
            mn = min(mn, len - (mp[el][n - 1] - index)); 
        }
        else if(mp[el][n - 1] == index)
        {
            mn = min(mn, len - (index - mp[el][0]));
            mn = min(mn, index - mp[el][n - 2]);
        }
        else{
            int idx = lower_bound(mp[el].begin(), mp[el].end(), index) - mp[el].begin();
            mn = min(mn, min(mp[el][idx] - mp[el][idx - 1], mp[el][idx + 1] - mp[el][idx]));
        }
        return mn;
    }
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        map<int, vector<int>>mp;
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            mp[nums[i]].push_back(i);
        }
        vector<int>ans;
        for(auto q: queries)
        {
            int index = q;
            int el = nums[index];

            ans.push_back(sol(index, el, mp, n));
        }
        return ans;
    }
};