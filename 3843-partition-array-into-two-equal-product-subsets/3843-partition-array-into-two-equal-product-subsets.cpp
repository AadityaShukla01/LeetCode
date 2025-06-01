class Solution {
public:
    typedef __int128 ll; 
    bool sol(int i, int n, vector<int>& nums, ll target,
             ll prod) {
        if (prod == target)
            return true;
        if (i >= n)
            return false;
        if (prod > target)
            return false;

        bool pick = sol(i + 1, n, nums, target, prod * nums[i]);

        bool notPick = sol(i + 1, n, nums, target, prod);

        return pick || notPick;
    }
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        ll prod = 1;
        int n = nums.size();
        for (auto el : nums)
            prod *= 1LL * el;
        if (prod / target != target)
            return false;

        return sol(0, n, nums, target, 1);
    }
};