class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        map<int, int> mp;

        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(i == j) continue;
                int pro = nums[i] * nums[j];
                mp[pro]++;
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(i == j) continue;
                int pro = nums[i] * nums[j];
                

                cnt += (mp[pro] - 2);
            }
        }

        return cnt;
    }
};