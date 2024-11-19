class Solution {
public:
    bool sol(int mi, vector<int>&nums, int k)
    {
        int cnt = 1;
        int n = nums.size();
        int pre = nums[0] + mi;

        for(int i=0; i<n; i++)
        {
            if(nums[i] >= pre)
            {
                pre = nums[i] + mi;
                cnt++;
            }
        }
        return cnt >= k;
    }
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        int n = price.size();
        int lo = 0;
        int hi = price[n - 1] - price[0];
        int ans = -1;
        while(lo <= hi)
        {
            int mi = lo + (hi - lo)/2;

            if(sol(mi, price, k))
            {
                ans = mi;
                lo = mi + 1;
            }
            else
                hi = mi - 1;
        }
        return ans;
    }
};