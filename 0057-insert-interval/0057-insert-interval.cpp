class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>>ans;
        if(n == 0) return {newInterval};
        int i = 0;
        while(i < n && intervals[i][1] < newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }
        if(i == n){
            ans.push_back(newInterval);
            return ans;
        }
        int mn = min(newInterval[0], intervals[i][0]);
        if(newInterval[1] < intervals[i][0]) 
        {
            ans.push_back(newInterval);
            mn = intervals[i][0];
        }
        while(i < n){
            if(mn != newInterval[0]) mn = intervals[i][0]; 
            int mx = max(newInterval[1], intervals[i][1]);
            while(i < n && intervals[i][0] <= mx){
                mx = max(mx, intervals[i][1]);
                i++;
            }
            ans.push_back({mn, mx});
            if(i < n) mn = intervals[i][0];
        }

        return ans;
    }
};