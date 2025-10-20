class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int>set;
        for(auto el: nums) set.insert(el);
        int el = 1;
        while(true){
            if(set.find(el * k) == set.end()) return el * k;
            el++;
        }
        return 0;
    }
};