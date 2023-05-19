class Solution {
public:
    int minOperations(vector<string>& log) {
        stack<string>st;
        for(int i=0 ;i<log.size() ;i++){
            if(st.size()>0 && log[i]=="../")
                st.pop();
            else if(log[i]=="./")
                continue;
            else if(log[i]!="../"){
                st.push(log[i]);
            }
        }
        if(st.empty()==false)
            cout<<st.top()<<endl;
        return st.size();
    }
};