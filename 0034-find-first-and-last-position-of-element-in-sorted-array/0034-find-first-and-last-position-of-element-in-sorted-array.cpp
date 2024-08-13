class Solution {
public:
    int first(vector<int>& nums, int target){
        int lo = 0;
        int hi = nums.size() - 1;
        int ans = -1;
        while(lo <= hi){
            int mi = lo + (hi - lo)/2;

            if(nums[mi] == target){
                ans = mi;
                hi = mi - 1;
            }
            else if(nums[mi] > target){
                hi = mi - 1;
            }
            else
                lo = mi + 1;
        }
        return ans;
    }
    int second(vector<int>& nums, int target){
        int lo = 0;
        int hi = nums.size() - 1;
        int ans = -1;
        while(lo <= hi){
            int mi = lo + (hi - lo)/2;

            if(nums[mi] == target){
                ans = mi;
                lo = mi + 1;
            }
            else if(nums[mi] > target){
                hi = mi - 1;
            }
            else
                lo = mi + 1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int i = first(nums, target);
        int j = second(nums, target);

        return {i, j};
    }
};