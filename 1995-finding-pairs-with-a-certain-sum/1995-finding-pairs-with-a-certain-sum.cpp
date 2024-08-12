class FindSumPairs {
public:
    map<int, int>m;
    vector<int>nums2;
    vector<int>nums1;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        this->nums2 = nums2;
        this->nums1 = nums1;
        for(auto el: nums2) m[el]++;
        
    }
    
    void add(int index, int val) {
        m[nums2[index]]--;
        m[nums2[index] + val]++;
        nums2[index]  = nums2[index] + val;
    }
    
    int count(int tot) {
        int cnt = 0;
        for(int i=0; i<nums1.size() && nums1[i] <= tot; i++){
            if(m.find(tot - nums1[i]) != m.end() && m[tot - nums1[i]] > 0)
                cnt += m[tot - nums1[i]];
        }
        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */