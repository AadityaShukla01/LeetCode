class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        int sum = 0;
        int pre = 0;
        int count = 0;
        sort(coins.begin(), coins.end());
        int i = 0;
        int n = coins.size();
        while (i < n && sum <= target) {
            if (sum + 1 < coins[i]) {
                count++;
                sum += (sum + 1);
            } else {
                sum += coins[i];
                i++;
            }
        }
        if(sum < target){
            while(sum < target){
                sum += (sum + 1);
                count++;
            }
        }
        return count;
    }
};