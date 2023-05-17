class Solution {
public:
    string reverseWords(string s) {
        vector<string>ans;
        string res="";
        for(int i=0;i<s.size();i++){
            if(s[i] != ' '){
                res+=s[i];
            }
            if(s[i]==' ' || i==s.size()-1){
                if(res.size()!=0)
                    ans.push_back(res);
                res="";
            }
        }
        reverse(ans.begin(),ans.end());
        res="";
        for(int i=0;i<ans.size();i++){
            if(i!=ans.size()-1)
            res+=ans[i]+" ";
            else
                res+=ans[i];
        }
        return res;
    }
};