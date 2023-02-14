class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0;
        int j=0;
        int n=nums.size();
        int sum=0;
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            sum=sum+nums[i];
            while(sum>=target){
                ans=min(ans,i-j+1);
                sum=sum-nums[j];
                j++;
            }
            
        }
        if(ans==INT_MAX)
        return 0;

        return ans;
    }
};