class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0, j = n - 1;
        // 0, 1, 4, 4, 5, 7
        long long count = 0;
        while(i < j){
            
            if(nums[i] + nums[j] > upper) j--;
            else if(nums[i] + nums[j] < lower) i++;
            else{
                // 3 ----- 11
                int temp = j;
                int max_allowed = lower - nums[i];
                int lb = lower_bound(nums.begin() + i, nums.end(), max_allowed) - nums.begin();
                cout << i << " " << j << " " << lb << "\n";
                count++;
                if(i == lb) lb++;
                if(nums[lb] + nums[i] >= lower){
                    count += j - lb;
                }
                i++;
            }
        }
        return count;
    }
};
// 1 2 5 7 9