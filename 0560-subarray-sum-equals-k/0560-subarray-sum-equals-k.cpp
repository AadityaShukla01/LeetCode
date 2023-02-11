class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //create a prefix array
       //in subarray questions generally we use prefix sum concept
       unordered_map<int,int>map;
        map[0]=1;
        int sum=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
            if(map.find(sum-k)!=map.end()){
                ans=ans+map[sum-k];
            }
            map[sum]++;
        }
        return ans;
    }
};