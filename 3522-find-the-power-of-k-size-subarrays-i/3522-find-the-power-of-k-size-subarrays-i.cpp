class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>a(n, 1);

        for(int i=n-2; i>=0; i--)
        {
            if(nums[i] == nums[i + 1] - 1)
            {
                a[i] = a[i + 1] + 1;
            }
        }

        vector<int>ans(n - k + 1, -1);
        for(int i=0; i<n; i++)
        {
            if(a[i] >= k)
            {
                ans[i] = nums[i] +  k - 1;
            }
        }
        return ans;
    }
};