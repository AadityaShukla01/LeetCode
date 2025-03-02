class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int, int>mp;
        vector<vector<int>>ans;

        for(auto el: nums1) mp[el[0]] += el[1];
        for(auto el: nums2) mp[el[0]] += el[1];

        for(auto el: mp) ans.push_back({el.first, el.second});

        return ans;
    }
};