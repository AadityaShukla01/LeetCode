class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        long long cnt = 0;
        int i = 0;
        while(i < n){
            if(nums[i] < target[i]){
                int st = i;
                while(i < n && nums[i] < target[i]) i++;
                int en = i - 1;
                int amount = 1e9;
                for(int l=st; l<=en; l++){
                    amount = min(amount, target[l] - nums[l]);
                }
                cnt += amount;
                for(int l=st; l<=en; l++){
                    nums[l] += amount;
                }
                if(amount != 0){
                    i = st;
                }
            }
            else if(nums[i] > target[i]){
                int st = i;
                while(i < n && nums[i] > target[i]) i++;
                int en = i - 1;
                int amount = 1e9;
                for(int l=st; l<=en; l++){
                    amount = min(amount, nums[l] - target[l]);
                }
                cnt += amount;
                for(int l=st; l<=en; l++){
                    nums[l] -= amount;
                }
                if(amount != 0){
                    i = st;
                }
            }
            else i++;
        }
        return cnt;
    }
};