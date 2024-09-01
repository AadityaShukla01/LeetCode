class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i=0; i<n-2; i++)
        {
            int j = i + 1;
            int diff = nums[j] - nums[i];
            int prev = i;
            int len = 1;
            while(j < n && nums[j] - nums[prev] == diff){
                prev = j;
                j++;
                len++;
            }
            cnt += max(0, len - 2);
        }
        return cnt;
    }
};