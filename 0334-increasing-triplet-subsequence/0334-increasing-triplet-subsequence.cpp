class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // TIME - 0(N) && SPACE 0(1)
        int n = nums.size();
        int left = INT_MAX; // will track smallest element uptil now
        int right = INT_MAX; // smallest element bigger than left
        

        for(int i=0;i<n;i++){
            if(nums[i] > right)
                return true; // found c in a < b < c

            if(nums[i] < left)
                left = nums[i];

            if(nums[i] > left && nums[i] < right)
                right = nums[i];
        }
        return false;
    }
};