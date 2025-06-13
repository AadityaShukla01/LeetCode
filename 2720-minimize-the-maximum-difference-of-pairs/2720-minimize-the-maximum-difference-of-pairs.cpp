class Solution {
public:
    int sol(int mi, vector<int>&nums, int p, int n){
        int cnt = 0;

        for(int i=0; i<n; i++){
            if(i + 1 < n && nums[i + 1] - nums[i] <= mi){
                cnt++;
                i++;
            }
        }

        return cnt >= p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int ans = -1;

        int lo = 0;
        int hi = nums[n - 1] - nums[0];

        while(lo <= hi){
            int mi = lo + (hi - lo)/2;

            if(sol(mi, nums, p, n)){
                ans = mi;
                hi = mi - 1; 
            }
            else lo = mi + 1;
        }
        return ans;
    }
};