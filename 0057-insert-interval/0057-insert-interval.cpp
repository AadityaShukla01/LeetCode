class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        // if(n == 0) return {newInterval};
        vector<vector<int>>ans;
        int i = 0;
        while(i < n && intervals[i][1] < newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }
        
        int mn = newInterval[0];
        int mx = newInterval[1];
        while(i < n && mx >= intervals[i][0]){
            mn = min(mn, intervals[i][0]);
            mx = max(mx, intervals[i][1]);
            i++;
        }
        ans.push_back({mn, mx});
        while(i < n) ans.push_back(intervals[i++]);
        return ans;
    }
};