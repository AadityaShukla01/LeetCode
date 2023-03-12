class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int len=1;
        int curr;
        int pre=0;
        for(int i=1;i<nums.size();i++){
            curr=nums[i]-nums[i-1];
            if((curr>0 && pre<=0) || (curr<0 && pre>=0)){
                len++;
                pre=curr;
            }
        }
        return len;
    }
};