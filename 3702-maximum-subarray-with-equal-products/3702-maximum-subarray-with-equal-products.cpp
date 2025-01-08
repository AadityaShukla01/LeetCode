class Solution {
public:
    int gcd(vector<int>&nums, int s, int e)
    {
        int gcd = nums[0];
        for(int i=s; i<=e; i++)
        {
            gcd = __gcd(nums[i], gcd);
        }
        return gcd;
    }
    int lcm(vector<int>&nums, int s, int e)
    {
        int l = nums[s];
        for(int i=s+1; i<=e; i++)
        {
            l = (l * nums[i]) / __gcd(nums[i], l);
        }
        return l;
    }
    long long product(vector<int>&nums, int s, int e)
    {
        long long pro = 1;
        for(int i=s; i<=e; i++){
            if(pro * nums[i] > INT_MAX) return 0;
            pro *= nums[i];
        }
        return pro;
    }
    int maxLength(vector<int>& nums) {
        int mxLen = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                int l = lcm(nums, i, j);
                int g = gcd(nums, i, j);
                int pro = product(nums, i, j);
                if(l * g == pro)
                    mxLen = max(mxLen, j - i + 1);
            }
        }
        return mxLen;
    }
};