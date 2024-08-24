class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();

        vector<int>bits(32, 0);

        for(int i=0; i<32; i++){
            for(auto el: nums){
                if(el & (1 << i)) bits[i]++;
            }
        }

        int ans = 0;

        for(int i=0; i<32; i++){
            if(bits[i] % 3) ans = ans | (1 << i);
        }
        return ans;
    }
};