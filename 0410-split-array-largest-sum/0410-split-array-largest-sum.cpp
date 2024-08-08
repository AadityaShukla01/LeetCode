class Solution {
public:
    int count(vector<int>&nums, int mi){
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
        int n = nums.size();
        int lo = *max_element(nums.begin(), nums.end());
        int hi = accumulate(nums.begin(), nums.end(), 0);
        int ans = -1;
        while(lo <= hi){
            int mi = lo + (hi - lo)/2;

            if(count(nums, mi) <= k){
                ans = mi;
                hi = mi - 1;
            }
            else lo = mi + 1;
        }
        return ans;
    }
};