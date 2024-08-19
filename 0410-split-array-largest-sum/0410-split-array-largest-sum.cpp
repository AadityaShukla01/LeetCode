class Solution {
public:
    int sol(int mi, vector<int>&nums){
        int sum = 0;
        int n = nums.size();
        int cnt = 1;
        for(int i=0; i<n; i++){
            sum += nums[i];

            if(sum > mi){
                sum = nums[i];
                cnt++;
            }
        }
        return cnt;
    }
    int splitArray(vector<int>& nums, int k) {
        int lo = *max_element(nums.begin(), nums.end());
        int hi = INT_MAX;
        int ans = -1;
        while(lo <= hi){
            int mi = lo + (hi - lo)/2;

            if(sol(mi, nums) <= k){
                ans = mi;
                hi = mi - 1;
            } else lo = mi + 1;
        }
        return ans;
    }
};