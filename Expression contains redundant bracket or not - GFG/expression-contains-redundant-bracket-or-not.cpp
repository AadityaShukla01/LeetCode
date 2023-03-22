//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  bool isOperator(char c){
      if(c=='+')
      return true;
      
      if(c=='-')
      return true;
      
      if(c=='*')
      return true;
      
      if(c=='/')
      return true;
      
      
      return false;
  }
    int checkRedundancy(string s) {
        // code here
        stack<char> st;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(ch=='(' || isOperator(ch)){
                st.push(ch);
            }
            else{
                if(ch==')'){
                bool flag=true;
                while(st.empty()==false && st.top()!='('){
                    if(isOperator(st.top())) 
                    flag=false;
                    st.pop();
                }
            if(flag) return true;
            st.pop();
            }
            
        }
        }
        return false;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
    
        string s; 
        cin>>s;
        
        Solution obj;
        int res = obj.checkRedundancy(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends