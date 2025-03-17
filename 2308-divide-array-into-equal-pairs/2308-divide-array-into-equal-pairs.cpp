class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        map<int, int>mp;
        for(auto el: nums) mp[el]++;

        for(auto it: mp){
            if(it.second % 2) return false;
        }
        return true;
    }
};