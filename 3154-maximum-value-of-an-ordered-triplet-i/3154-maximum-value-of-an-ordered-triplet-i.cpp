class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long mx = 0;
        int n = nums.size();
        vector<long long>maxTrack(n, 0);
        long long curr_max = 0;
        for(int i=n-1; i>=0; i--)
        {
            maxTrack[i] = curr_max;
            curr_max = max(curr_max, 1LL * nums[i]); 
        }
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(nums[i] - nums[j] > 0)
                {
                    mx = max(mx, 1LL * (nums[i] - nums[j]) * maxTrack[j]);
                }
            }
        }
        return mx;
    }
};