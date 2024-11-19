class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // find a set bit in the xorr
        // that bit means the position where these 2 single
        // numbers differ
        // form 2 groups 
        // xorr of each group will be answer
        // others will be cancel out each other

        int xorr = 0;

        for(auto el: nums) xorr = xorr ^ el;

        int bit;

        for(int i=0; i<32; i++)
        {
            if(xorr & (1 << i)){
                bit = i;
                break;
            }
        }

        int group1 = 0, group2 = 0;

        for(auto el: nums)
        {
            if(el & (1 << bit))
                group1 ^= el;
            else group2 ^= el;
        }

        return {group1, group2};
    }
};