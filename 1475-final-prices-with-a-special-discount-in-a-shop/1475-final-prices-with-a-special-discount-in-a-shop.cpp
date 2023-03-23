class Solution {
public:
    vector<int>sol(vector<int>& prices){
        int n=prices.size();
        vector<int>ans;
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                ans.push_back(0);
            }
            else if(st.empty()==false && st.top()<=prices[i]){
                ans.push_back(st.top());
            }
            else if(st.empty()==false && st.top()>prices[i]){
                while(st.empty()==false && st.top()>prices[i]) st.pop();
                if(st.size()==0) ans.push_back(0);
                else
                    ans.push_back(st.top());
            }
            st.push(prices[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    vector<int> finalPrices(vector<int>& prices) {
        vector<int>res=sol(prices);
        for(int i=0;i<prices.size();i++){
            res[i]=prices[i]-res[i];
        }
        return res;
    }
};