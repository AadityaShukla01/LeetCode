class Solution {
public:
    int maximumLength(vector<int>& nums) {
        // 4 cases are possible
        // 1. OO 2. EE
        int n = nums.size();
        int oddCount = 0, evenCount = 0, cnt1 = 0, cnt2 = 0;
        for (auto el : nums) {
            if (el % 2)
                oddCount++;
            else
                evenCount++;
        }
        // 3. OE 4. EO
        bool f1 = false, f2 = false;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 && !f1) {
                cnt1++;
                f1 = !f1;
            } else if (nums[i] % 2 == 0 && f1) {
                cnt1++;
                f1 = !f1;
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0 && !f2) {
                cnt2++;
                f2 = !f2;
            } else if (nums[i] % 2 && f2) {
                cnt2++;
                f2 = !f2;
            }
        }

        return max({oddCount, evenCount, cnt1, cnt2});
    }
};