class Solution {
public:
    vector<vector<int>> ans;
    void sol(int i, vector<int>&nums, int &target, int n, vector<int>&temp){
        if(target < 0) return;
        if(i >= n){
            if(target == 0)
                ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        target -= nums[i];
        sol(i + 1, nums, target, n, temp);
        temp.pop_back();
        target += nums[i];
        while(i  + 1 < n && nums[i + 1] == nums[i]) i++;
        sol(i + 1, nums, target, n, temp);
    }
    vector<vector<int>> combinationSum2(vector<int>& a, int target) {
        int n = a.size();
        sort(a.begin(), a.end());
        vector<int>temp;
        sol(0, a, target, n, temp);
        return ans;
    }
};
// take example 1 1 7 we will get duplicate answers 1, 7 & another 1, 7
// to avoid this we can put a check that if we are not considering an element
// then we will not consider any of it again so for that we put a while condition