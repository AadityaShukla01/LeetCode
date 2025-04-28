class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long count = 0;
        int i = 0, j = 0;
        long long p = 0;
        while(i < n){
            p += nums[i];

            while(p * (i - j + 1) >= k){
                p -= nums[j];
                j++;
            }

            count += (i - j + 1);
            i++;
        }
        return count;
    }
};