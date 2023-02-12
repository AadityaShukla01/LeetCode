class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n=arr.size();
        int sum=0;
        vector<int>ans;
        ans.push_back(0);
        for(int i=0;i<arr.size();i++){
            sum=sum+arr[i];
            ans.push_back(sum);
        }
        sum=0;
        for(int k=0;k<ans.size();k++){
            for(int l=k+1;l<ans.size();l+=2){
                sum=sum+(ans[l]-ans[k]) ;
            }
        }
        return sum;
    }
};


//1 2 3 4 5 

// 1  2 3 4 5 

//123
//234
//345
//12345