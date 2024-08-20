class Solution {
public:

    bool doesValidArrayExist(vector<int>& nums) {
        int n = nums.size();
        int xorr = 0;
        for(auto el: nums) xorr = xorr ^ el;

        return xorr == 0;
    }
};