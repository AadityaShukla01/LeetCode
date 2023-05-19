class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>st;
        vector<int>ans;
        for(int i=temperatures.size()-1;i>=0;i--){
            if(st.empty()==true){
                ans.push_back(0);
            }
            else if(st.empty()==false && temperatures[st.top() ]>temperatures[i])
               ans.push_back(st.top()-i);

        else if(st.empty()==false && temperatures[st.top()]<=temperatures[i]){
                while(st.empty()==false && temperatures[st.top()]<=temperatures[i])
                    st.pop();
                    if(st.size()==0)
                        ans.push_back(0);
                    else
                        ans.push_back(st.top()-i);
            }
            st.push(i);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};