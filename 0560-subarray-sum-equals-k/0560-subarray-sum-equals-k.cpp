class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        // a1  - a2 = k
        // a1 a2 a3 a4 a5
        unordered_map<int, int>map;
        int count = 0;
        int prefixSum = 0;
        for(int i=0; i<n; i++){
            prefixSum += nums[i];

            if(map.find(prefixSum - k) != map.end()){
                count += map[prefixSum - k];
            }

            map[prefixSum]++;
            if(prefixSum == k)
                count++;
        }
        return count;
    }
};