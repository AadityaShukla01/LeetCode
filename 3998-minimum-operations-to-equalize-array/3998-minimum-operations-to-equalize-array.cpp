class Solution {
public:
    int minOperations(vector<int>& nums) {
        set<int>set;

        for(auto el: nums) set.insert(el);

        return set.size() == 1 ? 0 : 1;
    }
};