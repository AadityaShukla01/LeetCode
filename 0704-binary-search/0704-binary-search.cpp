class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        
        while(s<=e){
            int m=(s+e)/2;
            
            if(target==nums[m])
                return m;
            else if(target > nums[m])
                s=m+1;
            else
                e=m-1;
        }
        return -1;
    }
};