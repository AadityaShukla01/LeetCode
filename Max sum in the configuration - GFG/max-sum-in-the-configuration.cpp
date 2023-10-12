//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int max_sum(int A[],int N);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
        {
            cin>>A[i];
        }

        cout<<max_sum(A,N)<<endl;
        /*keeping track of the total sum of the array*/

    }
}

// } Driver Code Ends


/*You are required to complete this method*/
int max_sum(int A[],int N)
{
//Your code here
    long long curr_sum = 0;
    long long curr_ans = 0;
    for(int i=0; i<N; i++)
        curr_sum += A[i];
    
    for(int i=0; i<N; i++)
        curr_ans += (i*A[i]);
    long long maxi = curr_ans;
    for(int i=1; i<N; i++){
        long long res = (curr_ans) - (curr_sum - A[i-1]) + (N-1)*A[i-1];
        maxi = max(maxi, res);
        curr_ans = res;
    }
    return maxi;
}