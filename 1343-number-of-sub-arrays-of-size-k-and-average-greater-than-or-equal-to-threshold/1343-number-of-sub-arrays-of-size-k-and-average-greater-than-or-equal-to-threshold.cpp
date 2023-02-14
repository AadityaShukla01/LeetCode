class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum=0;
        int q=0;
        for(int i=0;i<k;i++){
            sum=sum+arr[i];
        }
        int count=sum/k;
        if(count>=threshold){
            q++;
        }

        for(int i=k;i<arr.size();i++){
            sum=sum-arr[i-k];
            sum=sum+arr[i];

            if(sum/k>=threshold){
                q++;
            }
        }
        return q;
    }
};