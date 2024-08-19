class Solution {
public:
    vector<string>ans;
    void sol(int i, int n, string &s, string &temp){
        if(i == n){
            ans.push_back(temp);
            return;
        }
        if(isalpha(s[i])){
            // no change

            temp.push_back(s[i]);
            sol(i+1, n, s, temp);
            temp.pop_back();


            // change
            if(s[i] - 'a' >= 0){
                temp.push_back(s[i] - 32);
                sol(i+1, n, s, temp);
                temp.pop_back();
            }
            else {
                temp.push_back(s[i] + 32);
                sol(i+1, n, s, temp);
                temp.pop_back();
            }
        }
        else{
            temp.push_back(s[i]);
            sol(i+1, n, s, temp);
            temp.pop_back();
        }
    }
    vector<string> letterCasePermutation(string s) {
        string temp = "";
        int n = s.size();
        sol(0, n, s, temp);
        return ans;
    }
};