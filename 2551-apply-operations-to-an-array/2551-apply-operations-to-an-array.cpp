class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        int zero = 0;
        for(int i=0; i<n-1; i++)
        {
            if(nums[i] == 0) zero++;
            if(nums[i] == nums[i + 1]){
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        if(nums[n - 1] == 0) zero++;

        for(int i=0; i<n; i++)
        {
            if(nums[i]) ans.push_back(nums[i]);
        }

        for(int i=0; i<zero; i++) ans.push_back(0);

        return ans;
    }
};