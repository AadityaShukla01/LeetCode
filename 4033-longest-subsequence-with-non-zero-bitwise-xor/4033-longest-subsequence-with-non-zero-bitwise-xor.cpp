class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xorr = 0;
        bool hasNonZero = false;
        for(auto el: nums){
            if(el) hasNonZero = true;
            xorr = xorr ^= el;
        } 

        if(!xorr) {
            return !hasNonZero ? 0 : n - 1;
        }
        return n;
    }
};