class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0;
        int up=nums.size()-1;

        while(low<=up){
            int m=low+(up-low)/2;
            if(nums[m] == target) return m;
            
            //check if we are in left sorted part or ryt
            if(nums[low] <=nums[m]){
                //target is between low & m
                if(target<=nums[m] && target>=nums[low])
                    up=m-1;
                else low=m+1;
            }
            // in ryt sorted path
            else{
                if(target>=nums[m] && target<=nums[up])
                    low=m+1;
                else up=m-1;
            }
        }
        return -1;
    }
};