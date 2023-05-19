class Solution {
public:
    int minSwaps(string s) {
        int left=0;
        stack<char>st;
        for(auto i:s){
            //put bekar part in stack kyoki acha part to pop karre
            if(i==']' && st.size()>0 )
                st.pop();
            else if(i=='[')
                st.push(i);
        }
        //bekar part me aadhe ulte karo to proper pair miljayenge
        return (st.size()+1)/2;
    }
};