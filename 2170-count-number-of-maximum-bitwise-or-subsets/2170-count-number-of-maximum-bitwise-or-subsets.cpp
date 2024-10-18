class Solution {
public:
    int cnt;
    void sol(int i, int n,int orr, vector<int>&nums, int mxorr)
    {
        if(i >= n){
            cnt += (orr == mxorr);
            return;
        }

        sol(i + 1, n, orr | (nums[i]), nums, mxorr);
        sol(i + 1, n, orr, nums, mxorr);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int mxorr = 0;

        for(auto el: nums) mxorr |= el;

        sol(0, n, 0, nums, mxorr);

        return cnt;
    }
};