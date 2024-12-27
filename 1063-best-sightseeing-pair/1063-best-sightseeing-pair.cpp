class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        // 3 4
        int n = values.size();
        stack<pair<int, int>>st;

        int mx = 0;
        for(int i=0; i<n; i++){

            if(st.empty() == false)
                mx = max(mx, values[i] - i + st.top().first);

            if(st.empty()) st.push({values[i] + i, i});
            else if(values[i] + i > st.top().first)
            {
                st.push({values[i] + i, i});
            }
            // cout << mx << "\n";
        }
        return mx;
    }
};