class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();

        int mx = arrays[0][arrays[0].size() - 1];
        int mn = arrays[0][0];
        int ans = INT_MIN;

        for(int i=1; i<n; i++){
            int curr_min = arrays[i][0];
            int curr_max = arrays[i][arrays[i].size() - 1];

            ans = max({ans, curr_max - mn, mx - curr_min});
            
            mx = max(mx, curr_max);
            mn = min(mn, curr_min);
        }
        return ans;     
    }
};