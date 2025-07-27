class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();

        int count = 0;

        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int el1 = -1, el2 = -1;
            for (int j = i; j < n; j++) {
                if (nums[j] != nums[i]) {
                    el2 = nums[j];
                    break;
                }
            }

            for (int j = i; j >= 0; j--) {
                if (nums[j] != nums[i]) {
                    el1 = nums[j];
                    break;
                }
            }

            if (el1 == -1 || el2 == -1)
                continue;

            if (el1 < nums[i] && el2 < nums[i]) {
                count++;
            }
            if (el1 > nums[i] && el2 > nums[i]) {
                count++;
            }

            while(i + 1 < n && nums[i] == nums[i + 1]) i++;
        }

        return count;
    }
};