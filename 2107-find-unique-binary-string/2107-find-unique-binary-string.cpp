class Solution {
public:
    string ans;
    void sol(int i, int n, string &temp, set<string>&set)
    {
        if(i >= n){
            if(set.find(temp) == set.end())
                ans = temp;
            return;     
        }

        temp += "1";
        sol(i + 1, n, temp, set);
        temp.pop_back();

        temp += "0";
        sol(i + 1, n, temp, set);
        temp.pop_back();
    }
    string findDifferentBinaryString(vector<string>& nums) {
        set<string>set;
        for(auto str: nums) set.insert(str);
        string temp = "";
        int n = nums.size(); 
        sol(0, n, temp, set);
        return ans;
    }
};