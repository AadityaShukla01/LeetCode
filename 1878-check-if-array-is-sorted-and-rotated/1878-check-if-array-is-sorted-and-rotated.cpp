class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int breakPoint = -1;
        for(int i=0; i<n-1; i++)
        {
            if(nums[i] > nums[i + 1]) {
                breakPoint = i + 1;
                break;
            }
        }
        if(breakPoint == -1) return true;
        for(int i=breakPoint; i<n-1; i++)
        {
            if(nums[i] > nums[i + 1]) return false; 
        }

        if(nums[n - 1] > nums[0]) return false;

        return true;
    }
};