class Solution {
public:
     vector<int>NSR(vector<int>&input){
        int n = input.size();
        vector<int>ans;
        stack<int>st;

        int null_in = n;
        for(int i=n-1; i>=0; i--){
            if(st.empty())
                ans.push_back(null_in);

            else if(st.empty() == false && input[st.top()] < input[i])
                ans.push_back(st.top());

            else if(st.empty() == false && input[st.top()] >= input[i]){
                while(st.empty() == false && input[st.top()] >= input[i])
                    st.pop();
                if(st.empty())
                    ans.push_back(null_in);
                else
                    ans.push_back(st.top());
            }
            st.push(i);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    vector<int>NSL(vector<int>&input){
        int n = input.size();
        vector<int>ans;
        stack<int>st;
        int null_in = -1;
        for(int i=0; i<n; i++){
            if(st.empty())
                ans.push_back(null_in);

            else if(st.empty() == false && input[st.top()] < input[i])
                ans.push_back(st.top());

            else if(st.empty() == false && input[st.top()] >= input[i]){
                while(st.empty() == false && input[st.top()] >= input[i])
                    st.pop();
                if(st.empty())
                    ans.push_back(null_in);
                else
                    ans.push_back(st.top());
            }
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>nsl = NSL(heights);
        vector<int>nsr = NSR(heights);
        int ans = -1e9;
        for(int i=0; i<n; i++){
            int l = nsl[i];
            int r = nsr[i];

            int len = r - l - 1;

            ans = max(ans, len*heights[i]);
        }
        return ans;
    }
};