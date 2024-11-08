class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int xorr = 0;
        for(auto el: nums) xorr ^= el;
        int n = nums.size();
        vector<int>ans(n);
        
        for(int i=n-1; i>=0; i--)
        {
            int num = 0;
            for(int j=maximumBit - 1; j>=0; j--)
            {
                if(!(xorr & (1 << j)))
                {
                    num |=  (1 << j);
                }
            }
            ans[i] = num;
            xorr ^= nums[i];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};