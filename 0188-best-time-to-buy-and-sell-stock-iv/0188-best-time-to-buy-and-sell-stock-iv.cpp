class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int a = prices.size();
        // vector<vector<vector<int>>> dp(prices.size()+1, vector<vector<int>>(2, vector<int>(3, 0)));

        vector<vector<int>>after(2,vector<int>(k+1,0));
        vector<vector<int>>cur(2,vector<int>(k+1,0));
        //i buy prices

        for(int i=prices.size()-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int limit=1;limit<=k;limit++){
                    if(buy==1){
                        cur[buy][limit]=max(after[0][limit]-prices[i],after[1][limit]);
                    }
                    else{
                        cur[buy][limit]=max(after[1][limit-1]+prices[i],after[0][limit]);
                    }
                }
            }
            after=cur;
        }
        return after[1][k];
    }
};