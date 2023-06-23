class Solution {
public:
    
    void sol(int i, vector<int>& nums, int target, vector<vector<int>> &ans, vector<int> &temp){
        if(target == 0){
            ans.push_back(temp);
            return ;
        }

        if(target < 0 || i >= nums.size())
            return ;

        // for(int i=0; i<nums.size(); i++){
        //     if(nums[i] <= target){
        //         temp.push_back(nums[i]);
        //         sol(nums, target - nums[i], ans, temp);
        //         temp.pop_back();
        //     }
        // }

        // pick and not pick approach
        sol(i+1, nums, target, ans, temp);
        temp.push_back(nums[i]);
        sol(i, nums, target - nums[i], ans, temp);
        temp.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sol(0, nums, target, ans, temp);

        return ans;
    }
};