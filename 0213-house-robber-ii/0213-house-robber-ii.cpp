class Solution {
public:
    int sol(vector<int>& nums) {
        int n=nums.size();

      
        int pre=nums[0];
        int pre2=0;

        for(int i=1;i<n;i++){
            int pick=nums[i];
            if(i>1)
            pick+=pre2;

            int notPick=0+pre;

            int curr=max(pick,notPick);
            pre2=pre;
            pre=curr;

        }
        return pre;
    }
    
    int rob(vector<int>& nums) {
        vector<int>ans1;
        vector<int>ans2;
        if(nums.size()==1)
        return nums[0];
        if(nums.size()>1)
        for(int i=0;i<nums.size();i++){
            if(i!=0)
            ans1.push_back(nums[i]);
        
        if(i!=nums.size()-1)
            ans2.push_back(nums[i]);
        }

        return max(sol(ans1),sol(ans2));
    }
};