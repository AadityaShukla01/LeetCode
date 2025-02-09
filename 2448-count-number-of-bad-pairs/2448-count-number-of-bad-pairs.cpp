class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        
        map<int, int>mp;

        for(int i=0; i<n; i++)
        {
            mp[nums[i] - i]++;
        }
        long long ans = 0;
        for(int i=0; i<n; i++)
        {
            int cnt = mp[nums[i] - i] - 1;
            mp[nums[i] - i] -= 1;
            ans += cnt;
        }

        return 1LL * n * (n - 1) /2 - ans;
    }
};