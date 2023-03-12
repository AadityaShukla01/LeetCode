class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int>map;
        int ans=1;
        for(auto i:arr){
                map[i]=map[i-difference]+1;
                ans=max(ans,map[i]);
        } 
            return ans;
    }
};