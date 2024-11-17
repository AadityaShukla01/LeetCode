class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                int dir = 0;
                int in = i;
                vector<int>temp = nums;
                while (in >= 0 && in < n) {
                    if (nums[in] == 0) {
                        if (dir == 0)
                            in++;
                        else
                            in--;
                    } else {
                        nums[in]--;
                        dir = !dir;
                        if (dir == 0)
                            in++;
                        else
                            in--;
                    }
                }
                bool f = 1;
                for(int j=0; j<n; j++)
                {
                    if(nums[j]) f = 0; 
                }
                cnt += f;
                nums = temp;


                dir = 1;
                in = i;
                while (in >= 0 && in < n) {
                    if (nums[in] == 0) {
                        if (dir == 0)
                            in++;
                        else
                            in--;
                    } else {
                        nums[in]--;
                        dir = !dir;
                        if (dir == 0)
                            in++;
                        else
                            in--;
                    }
                }
                f = 1;
                for(int j=0; j<n; j++)
                {
                    if(nums[j]) f = 0; 
                }
                cnt += f;
                nums = temp;
            }
        }
        return cnt;
    }
};