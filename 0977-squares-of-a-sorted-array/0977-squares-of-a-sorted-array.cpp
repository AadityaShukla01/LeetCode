class Solution {
public:
    vector<int> sortedSquares(vector<int> &nums) {
        int i=0;
        int j=nums.size()-1;
        vector<int>ans;
        int l=0;
        //we are putting largest element first so we will get array sorted in ulti
        while(i<=j){
            if(abs(nums[i]) > abs(nums[j])){
                int num=nums[i]*nums[i];
                ans.push_back(num);
                i++;
            }
            else{
                int num=nums[j]*nums[j];
                ans.push_back(num);
                j--;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};