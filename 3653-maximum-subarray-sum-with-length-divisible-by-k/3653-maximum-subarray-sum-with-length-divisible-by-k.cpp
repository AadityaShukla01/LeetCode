class Solution {
public:
    // saw solution
    // we are finding min length of subarray ending at i and subtracting it from total sum
    // i % k -> length must be multiple of k
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long mx = -1e16;


        vector<long long>minPs(k, 1e15);
        vector<long long>ps(n + 1);

        ps[0] = 0;
        for(int i=1; i<=n; i++)
        {
            ps[i] = ps[i - 1] + nums[i - 1];
        }

        for(int i=0; i<=n; i++)
        {
            if(i >= k)
            {
                mx = max(mx, ps[i] - minPs[i % k]);
            }

            minPs[i % k] = min(minPs[i % k], ps[i]);
        }
        return mx;
    }
};