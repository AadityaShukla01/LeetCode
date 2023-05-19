class Solution {
public:
    int calPoints(vector<string>& ok) {
        stack<int>st;
        int n=ok.size();
        for(int i=0 ;i<n ;i++){
            if(ok[i] == "C"){
                st.pop();
            }
            else if(ok[i] == "+"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.push(a);
                int sum=a+b;
                st.push(sum);
            }
            else if(ok[i] =="D"){
                int a= st.top();
                int no =2*a;
                st.push(no);
            }
            else{
                //stoi works only for string not for char
                st.push(stoi(ok[i]));
            }
        }
        int sum=0;
        while(st.size() != 0){
            int a=st.top();
            sum+=a;
            st.pop();
        }
        return sum;
    }
};