//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    bool knows(vector<vector<int> >& M, int a, int b){
        return M[a][b];
    }
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here
        stack<int>st;
        for(int i=0;i<n;i++){
            st.push(i);
            
            while(st.size() != 1){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                
                if(knows(M,a,b))
                    st.push(b);
                else
                    st.push(a);
            }
        }
        int ans=st.top();
        // cout<<ans;
        for(int i=0;i<n;i++)
            if(M[ans][i] == 1) return -1;
        for(int i=0;i<n;i++){
            if(i!=ans){
                if(M[i][ans]==0) return -1;
            }
        }
        return ans;
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