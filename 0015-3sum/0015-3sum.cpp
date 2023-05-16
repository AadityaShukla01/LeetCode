class Solution {
public:
    vector<vector<int>>ans;  
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            int l=i+1;
            int u=nums.size()-1;

            while(l<u){
                if(nums[i]+nums[l]+nums[u]<0)
                    l++;
                else if(nums[i]+nums[l]+nums[u]>0)
                    u--;
                else{
                    int low=nums[l];
                    int upper=nums[u];

                    ans.push_back({nums[i],nums[l],nums[u]});
                    //to prevent repetion
                    //moving ahead unti we find a differnent element
                    while(l<u && nums[l]==low) l++;
                    while(l<u && nums[u]==upper) u--;
                }
            }
            while(i+1 < nums.size() && nums[i] == nums[i+1]) i++;
        }
        return ans;
    }
};