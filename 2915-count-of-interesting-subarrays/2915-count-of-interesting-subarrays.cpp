class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] % modulo == k) nums[i] = 1;
            else nums[i] = 0;
        }

        long long sum = 0;
        long long ans = 0;
        map<int, int>mp;
        mp[0] = 1;
        for(int i=0; i<n; i++){
            sum = sum + nums[i];
            int m = sum % modulo;

            // (p[j] - p[i]) % modulo = k
            // (p[j] - k + modulo) = p[i] % modulo
            // added + modulo to handle negative sum
            // p[j] = sum from 0...j
            // basically we need to find a subarray having sum % modulo as target
            int target = (sum - k + modulo) % modulo;

            if(mp.find(target) != mp.end())
                ans += mp[target];
            mp[m]++;
        }
        return ans;
    }
};