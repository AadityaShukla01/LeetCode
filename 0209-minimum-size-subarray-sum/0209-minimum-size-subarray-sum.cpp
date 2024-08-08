class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minLen = INT_MAX;

        int i = 0, j = 0;
        int curr_sum = 0;
        while(i < n && j < n){
            curr_sum += nums[i];

            
            while(curr_sum >= target){
                minLen = min(minLen, i - j + 1);
                curr_sum -= nums[j++];
            }
            i++;
        }
        if(minLen == INT_MAX) return 0;
        return minLen;
    }
};