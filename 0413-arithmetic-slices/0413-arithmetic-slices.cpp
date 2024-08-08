class Solution {
public:
    int sol(int num){
        int len = num - 2;

        return len*(len + 1)/2;
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        int count = 0;
        int n = nums.size();

        for(int i=0; i<n-1; i++){
            int diff = nums[i + 1] - nums[i];

            int len = 1;
            int cnt = 0;
            while(i + 1 < n && nums[i + 1] - nums[i] == diff){
                len++;
                i++;
            }
            
            i--;
            
            cout << len << "\n";
            count += sol(len);
        }
        return count;
    }
};