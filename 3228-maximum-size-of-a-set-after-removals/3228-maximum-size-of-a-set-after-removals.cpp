class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        map<int, int>mp1, mp2;
        for(auto el: nums1) mp1[el]++;
        for(auto el: nums2) mp2[el]++;

        set<int>s;
        int op = n/2;
        int cnt = 0;
        for(auto el: nums1){
            if(mp2.find(el) == mp2.end() && s.find(el) == s.end()){
                if(cnt < n/2){
                    cnt++;
                    s.insert(el);
                }
            }
        }
        for(auto el: nums1){
            if(s.find(el) == s.end()){
                if(cnt < n/2){
                    cnt++;
                    s.insert(el);
                }
            }
        }
        op = n/2;
        cnt = 0;
        for(auto el: nums2){
            if(mp1.find(el) == mp1.end() && s.find(el) == s.end()){
                if(cnt < n/2){
                    cnt++;
                    s.insert(el);
                }
            }
        }
        for(auto el: nums2){
            if(s.find(el) == s.end()){
                if(cnt < n/2){
                    cnt++;
                    s.insert(el);
                }
            }
        }
        return s.size();
    }
};