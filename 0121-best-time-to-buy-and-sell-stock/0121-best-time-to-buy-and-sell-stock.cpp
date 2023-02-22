class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curr=-1;
        int mini=1e9;
        
        for(int i=0;i<prices.size();i++){
            mini=min(mini,prices[i]);
            curr=max(curr,prices[i]-mini);
        }
        return curr;
    }
};