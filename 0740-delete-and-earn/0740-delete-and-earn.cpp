class Solution {
public:
int dp[100001];
int sol(int i,vector<int>& array,int n){
    if(i>=n) return 0;

    int pick=0;
    int notPick=0;

    if(dp[i] != -1) return dp[i];

    //house robber logic i*array[i] to include all elements if same type eg test case 2
    pick=sol(i+2,array,n)+i*array[i];    
    notPick=sol(i+1,array,n);

    return dp[i] = max(pick,notPick);
}
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        //size of count array
        int a = *max_element(nums.begin(),nums.end());

        memset(dp,-1,sizeof(dp));

        vector<int>array(a+1,0);
        for(int i=0;i<n;i++){
            array[nums[i]]++;
        }
        return sol(0,array,a+1);
    }
};