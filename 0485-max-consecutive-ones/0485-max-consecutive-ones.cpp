class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int q=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                ++q;
                ans=max(ans,q);
            }
            else{
                q=0;
            }
        }
        return ans;
    }
};