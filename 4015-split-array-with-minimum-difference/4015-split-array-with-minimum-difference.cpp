class Solution {
public:
    long long splitArray(vector<int>& nums) {
        long long ans = 1e15;
        int n = nums.size();
        long long sum = 0;
        for (auto el : nums)
            sum += el;
        int start = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] > nums[i + 1]) {
                start = i;
            } else
                break;
        }
        long long curr_sum = 0;
        long long prev = -1e15;
        for (int i = 0; i < n; i++) {
            if (nums[i] > prev) {
                curr_sum += nums[i];
                prev = nums[i];

                if (i >= start || (i - start) == -1) {
                    ans = min(ans, 1LL* abs(curr_sum - (sum - curr_sum)));
                }
            } else {
                if (i >= start) {
                    ans = min(ans, 1LL * abs(curr_sum - (sum - curr_sum)));
                }
                else return -1;
            }
        }

        
        return ans;
    }
};