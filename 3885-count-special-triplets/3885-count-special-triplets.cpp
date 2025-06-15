class Solution {
public:
    const int mo = 1e9 + 7;
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        map<int, int>mp;
        for(auto el: nums) mp[el]++;

        map<int, int>curr;
        long long ans = 0;

        for(int i=0; i<n; i++){
            
            int left = curr[nums[i] * 2];
            int right = mp[nums[i] * 2] - left;
            if(nums[i] == 0) right--;
            ans += 1LL * left * right;
            ans %= mo;

            curr[nums[i]]++;
        }

        return ans;
    }
};