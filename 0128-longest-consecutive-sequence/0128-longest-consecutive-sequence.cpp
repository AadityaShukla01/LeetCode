class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        set<int>set;
        for(auto el: nums) set.insert(el);
        int maxLen = 0;
        for(int i=0; i<n; i++){
            if(set.find(nums[i] + 1) != set.end()) continue;
            int len = 0;
            int num = nums[i];
            while(set.find(num) != set.end()){
                num--;
                len++;
            }
            maxLen = max(len, maxLen);
        }
        return maxLen;
    }
};