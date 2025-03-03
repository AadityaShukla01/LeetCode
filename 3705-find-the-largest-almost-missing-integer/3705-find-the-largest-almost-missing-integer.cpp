class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        map<int, int>mp;
        
        int n = nums.size();
        if(n == k) return *max_element(nums.begin(), nums.end());
        for(auto el: nums) mp[el]++;
        if(k == 1)
        {
            int mx = -1;
            for(auto it: mp)
            {
                if(it.second == 1) mx = max(mx, it.first);
            }
            return mx;
        }
        if(mp[nums[0]] == 1 && mp[nums[n - 1]] == 1)
            return max(nums[0], nums[n - 1]);
        else if(mp[nums[0]] == 1) return nums[0];
        else if(mp[nums[n - 1]] == 1) return nums[n - 1];
        else return -1;
    }
};