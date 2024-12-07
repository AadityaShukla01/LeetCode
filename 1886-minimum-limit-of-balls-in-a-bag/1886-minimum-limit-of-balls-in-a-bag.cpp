class Solution {
public:
    int sol(int mi, vector<int>&nums, int maxOperations)
    {
        int n = nums.size();
        int cnt = 0;

        for(auto el: nums)
        {
            if(el > mi)
            {
                cnt += (el % mi) ? (el / mi) : (el / mi) - 1;
            }

            if(cnt > maxOperations) return false;
        }
        return true;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int lo = 1;
        int hi = nums[n - 1];
        int ans = -1;
        while(lo <= hi)
        {
            int mi = lo + (hi - lo)/2;

            if(sol(mi, nums, maxOperations))
            {
                ans = mi;
                hi = mi - 1;
            }
            else lo = mi + 1;
        }
        return ans;
    }
};