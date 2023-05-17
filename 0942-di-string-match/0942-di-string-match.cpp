class Solution {
public:
    vector<int> diStringMatch(string s) {
        int l=0;
        int j=s.size();
        vector<int>ans;
        for(int i=0;i<s.size();i++){
            if(s[i]=='I'){
                ans.push_back(l);
                l++;
            }
            else if(s[i]=='D'){
                ans.push_back(j);
                j--;
             }
        }
        int n=s.size();
        int sum=n*(n+1)/2;
        int total=0;
        for(int i=0;i<ans.size();i++)
            total+=ans[i];
        int lostNo=sum-total;
        ans.push_back(lostNo);
        return ans;   
    }
};