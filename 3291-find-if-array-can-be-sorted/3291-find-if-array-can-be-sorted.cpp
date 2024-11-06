class Solution {
public:
    int countSetBits(int num)
    {
        int cnt = 0;
        for(int i=0; i<32; i++)
        {
            if(num & (1 << i)) cnt++;
        }
        return cnt;
    }
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        int mx = INT_MIN;
        for(int i=0; i<n; i++)
        {
            int j = i;
            while(j < n && countSetBits(nums[j]) == countSetBits(nums[i]))
            {
                if(nums[j] < mx)
                    return false;
                j++;
            }
            j = i;
            while(j < n && countSetBits(nums[j]) == countSetBits(nums[i]))
            {
                mx = max(mx, nums[j]);
                j++;
            }
            i = j - 1;
        }
        return true;
    }
};