class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int i = 0;
        int n = s.size();

        while (i < n) {
            string temp = "";
            if (i + k - 1 < n) {
                temp = s.substr(i, k);
                ans.push_back(temp);
            } 
            else {                
                temp = s.substr(i, k);
                while(temp.size() != k) temp += fill;
                ans.push_back(temp);
            }
            i += k;
        }
        return ans;
    }
};