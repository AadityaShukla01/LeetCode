class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, vector<int>>map;
        for(int i=0; i<n; i++){
            map[nums[i]].push_back(i);
        }

        for(auto it: map){
            vector<int> v = it.second;

            for(int i=0; i<v.size(); i++){
                if(i + 1 < v.size() && v[i + 1] - v[i] <= k) return true;
            }
        }
        return false;
    }
};