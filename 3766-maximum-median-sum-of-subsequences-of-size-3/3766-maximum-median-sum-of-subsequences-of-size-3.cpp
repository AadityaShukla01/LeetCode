class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int j = n - 2;
        long long sum = 0;

        int cnt = n / 3;

        while(cnt--){
            sum += nums[j];
            j -= 2;
        }    
        return sum;
    }
};