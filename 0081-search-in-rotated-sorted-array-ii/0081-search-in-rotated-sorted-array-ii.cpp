class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int i=0;
        int j=nums.size()-1;
        while(i<=j){
            int m=(i+j)/2;
            if(nums[m]==target)
                return true;
            
            else if(nums[i]>nums[m]){
                if(nums[m]<=target && nums[j]>=target)
                    i=m+1;
                else
                    j=m-1;
            }
            else if(nums[i]<nums[m]){
                if(nums[m]>=target && nums[i]<=target)
                    j=m-1;
                else
                    i=m+1;
            }
            else i++;
        }
        return false;
    }
};