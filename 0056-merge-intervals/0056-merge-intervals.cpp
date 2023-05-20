class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& it) {
        sort(it.begin(),it.end());
        stack<int>st;
        for(auto i:it){
            if(st.empty()==false && st.top()>=i[0] && st.top()<=i[1]){
                st.pop();
                st.push(i[1]);
            }
            else if(st.empty()==false && st.top()>i[0] && st.top()>i[1])
                continue ;
            else{
                st.push(i[0]);
                st.push(i[1]);
            }
        }
        vector<vector<int>>ans;
        while(st.size()>1){
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();
            ans.push_back({b,a});
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};