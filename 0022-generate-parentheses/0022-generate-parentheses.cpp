class Solution {
public:
     vector<string> generateParenthesis(int n) {
        vector<string>res;
        sol(res,"",n,0);
        return res;
    }
    void sol(vector<string>&res,string ans,int n,int m){
        //base case
        if(n==0 && m==0) //proper pair of balanced paranthesis
        {
            res.push_back(ans);
            ans="";
            return ;
        }
        if(m > 0){
            sol(res,ans+')',n,m-1);
        }
        if(n > 0){
            sol(res,ans+'(',n-1,m+1);
        }
    }
};