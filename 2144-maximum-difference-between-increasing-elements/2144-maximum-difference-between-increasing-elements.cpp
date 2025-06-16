class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans = -1;
        int mn = nums[0];
        int n = nums.size();
        for(int i=1; i<n; i++){
            if(nums[i] > mn)
                ans = max(ans, nums[i] - mn);
            mn = min(mn, nums[i]);
        }
        return ans;
    }
};