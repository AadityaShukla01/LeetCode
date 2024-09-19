class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        // vector<int>dp(n, 1);

        // for(int i=0; i<n; i++)
        // {
        //     for(int j=0; j<i; j++)
        //     {
        //         if(nums[i] > nums[j] && dp[i] < dp[j] + 1)
        //             dp[i] = dp[j] + 1;
        //     }
        // }

        // return *max_element(dp.begin(), dp.end());

        // optimal O(nlogn)

        vector<int>lis;

        for(int i=0; i<n; i++)
        {
            if(lis.empty() || lis.back() < nums[i])
                lis.push_back(nums[i]);

            else{
                int ub = lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();
                lis[ub] = nums[i];
            }
        }
        return lis.size();
    }
};