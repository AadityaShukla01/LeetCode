//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int arr[], int N)
    {
       // Your code here
       //stack banayenge o ki element or uske inedx ko store karega
       stack<pair<int,int>>st;
       vector<int>ans;
       for(int i=0;i<N;i++){
           if(st.size()==0){
               ans.push_back(-1);
           }
           else if(st.size()>0 && st.top().first>arr[i]){
               ans.push_back(st.top().second);
           }
           else if(st.size()>0 && st.top().first<=arr[i]){
                while(st.size()>0 && st.top().first <= arr[i])
                st.pop();
                if(st.size()==0)
                ans.push_back(-1);
                else
                ans.push_back(st.top().second);
           }
           st.push({arr[i],i});
       }
       ans[0]=1;
        for(int i=1;i<ans.size();i++){
            ans[i]=i-ans[i];
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
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends