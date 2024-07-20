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
    int maximalRectangle(vector<vector<char>>& matrix) {
        // maximum area of histogram on each row of matrix
        // max area of histogram = (nsr-nsl-1)*nums[i]
        // TC is O(n*n)

        int n = matrix.size();
        int m = matrix[0].size();
        int ans = -1e9;
        vector <int>height(m, 0);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == '1'){
                    height[j] += 1;
                }
                else height[j] = 0;
            }
            ans = max(ans, largestRectangleArea(height));
        }
        return ans;
    }
};