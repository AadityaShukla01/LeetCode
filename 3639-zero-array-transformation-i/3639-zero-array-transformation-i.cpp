class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int>v(n + 1, 0);

        for(auto q:queries){
            int a = q[0], b = q[1];
            v[a]++;
            v[b + 1]--;
        }
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += v[i];
            if(sum < nums[i]) return false;
        }

        return true;
    }
};