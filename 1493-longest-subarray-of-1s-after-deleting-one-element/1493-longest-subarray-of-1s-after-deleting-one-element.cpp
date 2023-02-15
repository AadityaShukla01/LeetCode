class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        //creating a map to store frequency of all elements
        int count[2]={0};
        int j=0;
        int ans=0;
        int maxFreq=0; //frequency of max 1s
        for(int i=0;i<nums.size();i++){
            count[nums[i]]++;
            maxFreq=max(maxFreq,count[1]);

            if((i-j+1)-maxFreq<=1){
                ans=max(ans,(i-j+1));
            }
            else{
                count[nums[j]]--;
                j++;
            }
        }
        return ans-1;
    }
};