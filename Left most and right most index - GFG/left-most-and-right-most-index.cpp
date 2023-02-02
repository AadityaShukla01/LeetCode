//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    long first(vector<long long> arr, long long x){
    // code here
        int start=0;
        int end=arr.size()-1;
        int res=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(arr[mid]==x){
                //aage ke liye check karo
                res=mid;
                end=mid-1;
            }
            else if(arr[mid]>x){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return res;
    }
    long second(vector<long long> arr, long long x){
        int start=0;
        int end=arr.size()-1;
        int res=-1;
        while(start<=end){
            
            int mid=start+(end-start)/2;
            
            if(arr[mid]==x){
                //aage ke liye check karo
                res=mid;
                start=mid+1;
            }
            else if(arr[mid]>x){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return res;
    }
    pair<long,long> indexes(vector<long long> arr, long long x)
    {
        int a=first(arr,x);
        int p=second(arr,x);
        
        pair<long,long> ans(a,p);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}

// } Driver Code Ends