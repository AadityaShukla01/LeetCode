class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int sumMx = 0;
        int mx = 0;

        int sumMn = 0;
        int mn = 0;

        int n = nums.size();

        for(int i=0; i<n; i++)
        {
            sumMx += nums[i];
            sumMn += nums[i];

            if(sumMx < 0) sumMx = 0;
            if(sumMn > 0) sumMn = 0;

            mx = max(mx, sumMx);
            mn = min(mn, sumMn);
        }
        return max(mx, abs(mn));
    }
};