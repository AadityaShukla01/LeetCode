class Solution {
public:
    int findMin(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        while(i<j){
            int m=(i+j)/2;
            if(nums[m]>nums[j]){
                i=m+1;
            }
            else if(nums[m]<nums[j])
                j=m;
            else
                j--; //since we want to go close to piot
                // if we do i++ we may loose it
        }
        return nums[j];
    }
};