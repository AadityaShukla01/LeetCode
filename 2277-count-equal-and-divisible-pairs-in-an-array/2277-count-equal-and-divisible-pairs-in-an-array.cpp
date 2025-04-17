class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        map<int, vector<int>>v;

        for(int i=0; i<n; i++)
        {
            if(v.find(nums[i]) != v.end())
            {
                for(auto idx: v[nums[i]]){
                    if((idx * i) % k == 0) cnt++;
                }
            }

            v[nums[i]].push_back(i);
        }
        return cnt;
    }
};