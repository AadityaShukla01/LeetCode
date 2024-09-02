class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        int mx = 0;
        int i = 0;
        while(i < n){
            int j = i + 1;
            int len = 1;
            while(j < n && nums[j] > nums[j - 1])
            {
                j++;
                len++;
            }
            mx = max(mx, len);
            i = j;
        }
        return mx;
    }
};