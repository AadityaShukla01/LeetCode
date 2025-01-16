class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int n = nums1.size(), m = nums2.size();
        if(n % 2 == 0 && m % 2 == 0) return 0;
        if(m % 2){
            for(auto el: nums1) ans ^= el;
        }
        if(n % 2){
            for(auto el: nums2)
                ans ^= el;
        }
        return ans;
    }
};