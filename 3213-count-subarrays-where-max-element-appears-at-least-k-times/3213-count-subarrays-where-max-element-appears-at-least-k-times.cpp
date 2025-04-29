class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx = 0;
        for(auto el: nums) mx = max(mx, el);

        long long count = 0;
        int i = 0, j = 0;
        int n = nums.size();
        int mxCnt = 0;
        
        while(i < n){
            if(nums[i] == mx) mxCnt++;

            if(mxCnt >= k){
                while(mxCnt >= k){
                    count += (n - i);
                    if(nums[j] == mx) mxCnt--;
                    j++;
                }
            }
            i++;
        }
        return count;
    }
};