class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int c = 0, el;

        for(int i=0; i<n; i++)
        {
            if(nums[i] == el){
                c++;
            }
            else if(c == 0) el = nums[i];
            else c--;
        }
        return el;
    }
};