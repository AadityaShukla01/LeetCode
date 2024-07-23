class Solution {
public:
    static bool comp(pair<int, int>&a, pair<int, int>&b){
        if(a.second == b.second) return a.first > b.first;
        return a.second < b.second;
    }
    
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        map<int, int>freq;
        for(auto el: nums) freq[el]++;
        vector<pair<int, int>>a;
        for(auto it: freq){
            a.push_back({it.first, it.second});
        }

        sort(a.begin(), a.end(), comp);
        vector<int>ans;
        for(auto it: a){
            int f = it.second;
            while(f--) ans.push_back(it.first);
        }
        return ans;
    }
};