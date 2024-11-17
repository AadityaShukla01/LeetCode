class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        vector<int>v(n + 1, 0);

        for(auto q: queries)
        {
            int a = q[0], b = q[1];
            v[a]++;
            v[b + 1]--;
        }
        int curr = 0;
        for(int i=0; i<n; i++)
        {
            curr += v[i];
            if(curr >= nums[i]) continue;
            else return false;
        }

        return true;
    }
};