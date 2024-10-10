class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<pair<int, int>>st;

        for(int i=0; i<n; i++)
        {
            if(st.empty()) st.push({nums[i], i});
            else if(st.top().first > nums[i])
                st.push({nums[i], i});
        }

        int mx = 0;

        for(int i=n-1; i>=0; i--)
        {
            if(st.empty() == false && st.top().first <= nums[i])
            {
                while(st.empty() == false && st.top().first <= nums[i])
                {
                    mx = max(mx, i - st.top().second);
                    st.pop();
                }
            }
        }
        return mx;
    }
};