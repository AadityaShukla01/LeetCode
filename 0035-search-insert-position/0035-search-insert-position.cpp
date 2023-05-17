class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size()-1;
        int mid=0;
        //if it is the largest element
        int ans=nums.size();
        while(start<=end){
            mid=(start+end)/2;
            
            if(nums[mid]==target)
                return mid;

            else if(nums[mid]>target){
                //since element will always be towards left of mid
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
};