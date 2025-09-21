class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int res = 0;
        for(auto el: nums){
            if(el % 2 == 0) res |= el;
        }
        return res;
    }
};