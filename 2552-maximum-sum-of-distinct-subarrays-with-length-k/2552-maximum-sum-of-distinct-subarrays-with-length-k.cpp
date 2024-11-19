class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum = 0;
        map<int, int>mp;
        long long mx = 0;
        int n = nums.size();
        for(int i=0; i<k; i++)
        {
            sum += nums[i];
            mp[nums[i]]++;
        }

        if(mp.size() == k) mx = max(mx, sum);

        for(int i=k; i<n; i++)
        {
            mp[nums[i - k]]--;
            mp[nums[i]]++;
            sum += nums[i];
            sum -= nums[i - k];
            if(mp[nums[i - k]] == 0)
                mp.erase(nums[i - k]);
            if(mp.size() == k)
                mx = max(mx, sum);
        }
        return mx;
    }
};