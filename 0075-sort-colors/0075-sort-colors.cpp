class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0;
        int mid=0;
        int high=nums.size()-1;

        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low] ,nums[mid]);
                    mid++;
                    //mid++ because we know about the new element
                //element to left of mid are getting sorted
                    low++;
            }
            else if(nums[mid]==1)
                mid++;
            else if(nums[mid]==2){
                swap(nums[high] ,nums[mid]);
                //not done mid++ because we dont know about the new element
                high--;
            }
        }
    }
};