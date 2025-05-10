class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int cntZero1 = 0, cntZero2 = 0;
        int sum1 = 0, sum2 = 0;

        for(auto el: nums1){
            if(el == 0) cntZero1++;
            else sum1 += el;
        }

        for(auto el: nums2){
            if(el == 0) cntZero2++;
            else sum2 += el;
        }

        if(sum1 + cntZero1 > sum2 && cntZero2 == 0) return -1;
        if(sum2 + cntZero2 > sum1 && cntZero1 == 0) return -1;

        return max(sum1 + cntZero1, sum2 + cntZero2);
    }
};