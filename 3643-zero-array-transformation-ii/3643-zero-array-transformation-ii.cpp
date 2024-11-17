class Solution {
public:
    bool sol(int mi, vector<int>&nums, vector<vector<int>>&queries)
    {
        int n = nums.size();
        vector<int>v(n + 1);

        for(int j=0; j<=mi; j++)
        {
            int a = queries[j][0];
            int b = queries[j][1];

            v[a]+=queries[j][2];
            v[b + 1] -= queries[j][2];
        }   
        int sum = 0;
        for(int j=0; j<n; j++)
        {
            sum += v[j];

            if(sum < nums[j]) return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int lo = 0;
        int hi = queries.size() - 1;
        int ans = -1;
        int f = 1;
        for(auto el: nums)
        {
            if(el) f = 0;
        }
        if(f) return 0;
        while(lo <= hi)
        {
            int mi = lo + (hi - lo)/2;

            if(sol(mi, nums, queries))
            {
                ans = mi + 1;
                hi = mi - 1;
            }
            else lo = mi + 1;
        }
        return ans;
    }
};