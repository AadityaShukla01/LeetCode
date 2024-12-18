class Solution {
public:
    vector<int>NSR(vector<int>&a)
    {
        int n = a.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=n-1; i>=0; i--)
        {
            if(st.empty()) ans[i] = 0;
            else if(!st.empty() && st.top() <= a[i])
            {
                ans[i] = st.top();
            }
            else if(!st.empty() && st.top() > a[i])
            {
                while(!st.empty() && st.top() > a[i])
                    st.pop();

                if(st.empty()) ans[i] = 0;
                else ans[i] = st.top();
            }

            st.push(a[i]);
        }
        return ans;
    }
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();

        vector<int>ans = NSR(prices);
        for(int i=0; i<n; i++)
        {
            ans[i] = prices[i] - ans[i];
        }
        return ans;
    }
};