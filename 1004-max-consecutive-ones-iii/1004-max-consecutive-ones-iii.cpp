class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int count[2]={0};
        int ans=0;
        int j=0;
        int maxFreq=0;
        for(int i=0;i<nums.size();i++){
            //window ko expand karte jayenge
            count[nums[i]]++;
            maxFreq=max(maxFreq,count[1]);

            //if remaining lesngth is less than or equal to k
            if((i-j+1)-maxFreq<=k){
                ans=max(ans,(i-j+1));
            }
            else{
                count[nums[j]]--;
                j++;
            }
        }
        return ans;
    }
};