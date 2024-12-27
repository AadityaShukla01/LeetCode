class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        // 3 4
        int n = values.size();
        stack<int>st;

        int mx = 0;
        for(int i=0; i<n; i++){

            if(st.empty() == false)
                mx = max(mx, values[i] - i + st.top());

            if(st.empty()) st.push(values[i] + i);
            else if(values[i] + i > st.top())
            {
                st.push(values[i] + i);
            }
            // cout << mx << "\n";
        }
        return mx;
    }
};