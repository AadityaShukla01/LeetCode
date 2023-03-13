class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum=-1e9;
        int currSum=-1e9;
        for(auto i:nums){
            currSum=max(i,currSum+i);
            maxSum=max(maxSum,currSum);
        }
        return maxSum;
    }
};