class Solution {
public:
    int countVowelStrings(int n) {
        vector<int>ans(5,1);
        while(n--){
            for(int i=3;i>=0;i--){
                ans[i]+=ans[i+1];
            }
        }
        return ans[0];
    }
};