class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        int n = intervals.size();
        if(n == 0) return {newInterval};
        int i = 0;
        if(intervals[0][0] > newInterval[1])
        {
            ans.push_back(newInterval);
            while(i < n) ans.push_back(intervals[i++]);
            return ans;
        } 
        for(i=0; i<n; i++)
        {
            if(intervals[i][1] <  newInterval[0]) ans.push_back(intervals[i]);
            else break;
        }

        if(ans.size() == n)
        {
            ans.push_back(newInterval);
            return ans;
        }

        int mx = newInterval[1];
        int mn = min(intervals[i][0], newInterval[0]);
        while(i < n && mx >= intervals[i][0])
        {
            mx = max(mx, intervals[i][1]);
            i++;
        }

        ans.push_back({mn, mx});

        while(i < n){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};