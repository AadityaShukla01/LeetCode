class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        int cnt = 0, j = 0, mx = 0;

        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                cnt++;
            }

            if(cnt > 1){
                while(cnt > 1){
                    if(nums[j] == 0) cnt--;
                    j++;
                }
            }

            mx = max(mx, i - j + 1 - cnt);
        }

        return mx == n ? n - 1 : mx;
    }
};