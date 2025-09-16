class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int mn = INT_MAX;

        for(auto t: tasks){
            mn = min(mn, t[0] + t[1]);
        }
        return mn;
    }
};