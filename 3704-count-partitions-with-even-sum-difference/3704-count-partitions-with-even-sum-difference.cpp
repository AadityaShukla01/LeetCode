class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum = 0;
        for(auto el: nums) sum += el;

        int cnt = 0;
        int curr = 0;
        int n = nums.size();
        for(int i=0; i<n-1; i++)
        {
            curr += nums[i];
            sum -= nums[i];

            if((curr - sum) % 2 == 0) cnt++;
        }

        return cnt;
    }
};