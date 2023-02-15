class Solution {
public:
    bool canJump(vector<int>& nums) {
        int steps=nums[0];
        for(int i=1;i<nums.size();i++){
            steps--;

            //not possible case
            if(steps<0)
            return false;

            //greedy approach
            if( nums [i] > steps){
                steps=nums[i];
            }

        }
        return true;
    }
};