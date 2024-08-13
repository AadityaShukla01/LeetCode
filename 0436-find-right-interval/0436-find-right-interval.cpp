class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int, int>mp;
        int n = intervals.size();
        vector<int>startValues(n);
        for(int i=0; i<intervals.size(); i++){
            int start = intervals[i][0];
            mp[start] = i;
            startValues[i] = start;
        }
        sort(startValues.begin(), startValues.end());
        vector<int>ans(n);
        for(int i=0; i<n; i++){
            int end = intervals[i][1];

            int lb = lower_bound(startValues.begin(), startValues.end(), end) - startValues.begin();
            if(lb == n) ans[i] = -1;
            else{
                int index = mp[startValues[lb]];
                ans[i] = index;
            }
        }
        return ans;
    }
};