class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        // algo
        //  1) from back find first index where arr[i] < arr[i+1]
        // 2)now from i+1 to n search for smallest element greater than it
        //  3) swap it with arr[i] and then reverse i+1 to n

        int breakPoint = -1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]){
                breakPoint = i;
                break;
            }
        }

        if (breakPoint == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        int mx = 1e9;
        int i = -1;
        for (int j = n - 1; j > breakPoint; j--) {
            if (nums[j] > nums[breakPoint]) {
                swap(nums[j], nums[breakPoint]);
                break;
            }
        }
        

        reverse(nums.begin() + breakPoint + 1, nums.end());
    }
};