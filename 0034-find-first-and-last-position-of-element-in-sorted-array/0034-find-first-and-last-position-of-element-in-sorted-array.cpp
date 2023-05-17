class Solution {
public:
    int sol(vector<int>& nums, int target){
        int l=0;
        int e=nums.size()-1;
        int ans=-1;
        while(l<=e){
            int m=l+(e-l)/2;
            if(nums[m]==target){
                ans=m;
                e=m-1;
                 //if element found search for left most occurence
            }
            else if(nums[m]>target)
                e=m-1;
            else
                l=m+1;
        }
        return ans;
    }
    int sol1(vector<int>& nums, int target){
        int l=0;
        int e=nums.size()-1;
        int ans=-1;
        while(l<=e){
            int m=(l+e)/2;
            if(nums[m]==target){
                ans=m;
                l=m+1;
                //if element found search for ryt most occurence
            }
            else if(nums[m]>target)
                e=m-1;
            else
                l=m+1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int a=sol(nums,target);
        int b=sol1(nums,target);
        return {a,b};
    }
};