class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
       vector<int>q(nums.size());
        int j=0;
        int l=1;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0 && j<nums.size()){
                q[j]=nums[i];
                j=j+2;
            }
            else if(nums[i]<0 && l<nums.size()){
                q[l]=nums[i];
                l+=2;
            }
        }
        return q;
    }
};