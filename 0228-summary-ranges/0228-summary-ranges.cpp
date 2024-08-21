class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        vector<string>ans;
        while(i < n){
            long long num = nums[i];
            long long original = num;
            while(i < n && nums[i] == num){
                num++;
                i++;
            }
            if(num - original > 1){
                ans.push_back({to_string(original) + "->" + to_string(num - 1)});
            }
            else{
                ans.push_back(to_string(original));
            }
        }
        return ans;
    }
};