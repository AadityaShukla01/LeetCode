class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            if(i - k >= 0 && i + k < n)
            {
                if(nums[i] > nums[i - k] && nums[i] > nums[i + k])
                    ans += nums[i];
                     
            }   
            else if(i - k >= 0 && nums[i] > nums[i - k]) ans += nums[i];
            else if(i + k < n && nums[i] > nums[i + k]) ans += nums[i]; 
            else if(i - k < 0 && i + k >= n) ans += nums[i];        
        }
        return ans;
    }
};