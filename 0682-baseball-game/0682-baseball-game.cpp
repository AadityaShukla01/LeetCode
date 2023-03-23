class Solution {
public:
    int calPoints(vector<string>& ok) {
        stack<int>st;

        for(int i=0;i<ok.size();i++){
            if(ok[i]=="C"){
                st.pop();
            }
            else if(ok[i]=="D"){
                int num=st.top();
                st.push(2*num);
            }
            else if(ok[i]=="+"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.push(a);
                st.push(a+b);
            }
            else
                st.push(stoi(ok[i]));
        }
        int ans=0;
        while(st.size()!=0){
            int num=st.top();
            ans+=num;
            st.pop();
        }
        return ans;
    }
};