class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans;
        double sum=0;
        
       
        //create a window
        for(int i=0;i<k;i++){
            sum=sum+nums[i];
        }
        double maxi=INT_MIN;
        maxi=max(maxi,sum/k);

        for(int i=k;i<nums.size();i++){
            sum=sum-nums[i-k];
            sum=sum+nums[i];

            maxi=max(maxi,sum/k);
        }
        return maxi;
    }
};