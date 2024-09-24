class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>ans;
        ans=nums;
        nums[0]=ans[0];
        int n=nums.size();
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum=sum+ans[i];
            nums[i]=sum;
        }
        return nums;
    }
};