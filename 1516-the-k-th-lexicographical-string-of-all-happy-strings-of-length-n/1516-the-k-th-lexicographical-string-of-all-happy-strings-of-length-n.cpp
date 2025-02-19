class Solution {
public:
    string ans;
    void sol(int i, int pre, int n, int k, string &temp, vector<char>&v, int& l)
    {
        if(i >= n){
            l++;
            if(l == k) ans = temp;
            return;
        }

        for(int j=0; j<3; j++)
        {
            if(pre != j){
                temp.push_back(v[j]);                
                sol(i + 1, j, n, k, temp, v, l);
                temp.pop_back();
                
            }
        }
    }
    string getHappyString(int n, int k) {
        vector<char>v = {'a', 'b', 'c'};
        string temp = "";
        int l = 0;
        sol(0, -1, n, k, temp, v, l);
        return ans;
    }
};