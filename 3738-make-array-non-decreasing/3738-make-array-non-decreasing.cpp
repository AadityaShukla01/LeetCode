class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int n = nums.size();
        int mx = INT_MIN;
        int cnt = 0;
        for(int i=0; i<n; i++)
        {
            if(nums[i] < mx) cnt++;
            mx = max(mx, nums[i]);
        }
        return n  - cnt;
    }
};