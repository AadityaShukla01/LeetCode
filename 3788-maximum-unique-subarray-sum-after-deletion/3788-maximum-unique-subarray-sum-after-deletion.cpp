class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        map<int, int>mp;

        int sum = 0, mx = INT_MIN;

        for(auto el: nums){
            if(mp.find(el) == mp.end() && el > 0){
                mp[el]++;
                sum += el;
            }
            mx = max(mx, el);
        }

        return mp.size() == 0 ? mx : sum;
    }
};