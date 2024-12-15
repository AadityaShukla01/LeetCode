class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int mx = events[0][1];
        int ans = events[0][0];

        int n = events.size();

        for(int i=1; i<n; i++)
        {
            int time = events[i][1] - events[i - 1][1];

            if(time > mx)
            {
                mx = time;
                ans = events[i][0];
            }
            else if(time == mx)
            {
                ans = min(ans, events[i][0]);
            }
        }
        return ans;
    }
};