class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        
        for(int i=0; i<n-2; i++)
        {
            int curr = nums[i];
            int sec = nums[i + 1];
            int last = nums[i + 2];

            if(curr + last == sec/2 && sec % 2 == 0) cnt++;
        }
        return cnt;
    }
};