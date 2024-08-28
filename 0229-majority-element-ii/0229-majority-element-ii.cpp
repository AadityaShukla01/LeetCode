class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // almost same as part 1, mooores algo
        int cnt1 = 0, cnt2 = 0;
        int n = nums.size();

        int el1 = -1, el2 = -1;

        for(int i=0; i<n; i++){
            if(cnt1 == 0 && nums[i] != el2){
                el1 = nums[i];
                cnt1++;
            }
            else if(cnt2 == 0 && nums[i] != el1){
                el2 = nums[i];
                cnt2++;
            }
            else if(nums[i] == el1){
                cnt1++;
            }
            else if(nums[i] == el2){
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }

        int c1 = 0, c2 = 0;
        int f = n/3;

        for(auto el: nums){
            if(el == el1){
                c1++;
            }
            else if(el == el2) c2++;
        }
        vector<int>ans;
        if(c1 > f) ans.push_back(el1);
        if(c2 > f) ans.push_back(el2);

        return ans;
    }
};