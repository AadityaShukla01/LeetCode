class Solution {
public:
    static bool comp(const vector<int>&a, const vector<int>&b){
        if(a[1] == b[1]) return a[0] < b[0];

        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end(), comp);

        stack<vector<int>>st;

        int i = 0;
        while(i < n){
            if(!st.size()) st.push(intervals[i]);
            else{
                if(st.top()[1] <= intervals[i][0]){
                    st.push(intervals[i]);
                }
            }
            i++;
        }
        cout << st.size();
        return n - st.size();
    }
};