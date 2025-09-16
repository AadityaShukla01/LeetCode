class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        set<int>set;
        vector<int>ans;
        for(auto el: nums) set.insert(el);

        
            while(k-- && set.size()){
                ans.push_back(*set.rbegin());
                set.erase(--set.end());
            }
        
        return ans;
    }
};