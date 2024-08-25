class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return 0;
        int maxJump = 0;
        int jump = 0;
        int index = -1;
        for(int i=0; i<n; i++){
            if(maxJump >= n - 1) return jump;
            int mx = maxJump;
            for(int j=i; j<=min(n, mx); j++){
                if(maxJump < nums[j] + j){
                    maxJump = nums[j] + j;
                    index = j;
                }
            }
            cout << index << "\n";
            i = index - 1;
            jump++;
        }
        return jump;
    }
};