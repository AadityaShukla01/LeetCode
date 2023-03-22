//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    bool knows(vector<vector<int> >& M,int a ,int b){
        return M[a][b];
    }
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int>st;
        for(int i=0;i<n;i++)
            st.push(i);
        
        while(st.size()!=1){
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();
            
            if(knows(M,a,b)){
                st.push(b);
            }
            else{
                st.push(a);
            }
        }
        int ans=st.top();
        //now we need to know whetether its a celebrity or not
        int zeroCount=0;
        int oneCount=0;
        bool zero=true;
        bool one=false;
        for(int i=0;i<n;i++){
            if(M[ans][i]==1)  zero=false;   
        }
        for(int i=0;i<n;i++){
            if(M[i][ans]==1)  oneCount++; 
        }
        if(oneCount==n-1 && zero) return ans;
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends