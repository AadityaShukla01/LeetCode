class Solution {
public:
    int countSeniors(vector<string>& str) {
        int count = 0;
        for(auto s: str){
            int n = s.size();
            int age = (s[n - 4] - '0')*10 + (s[n - 3] - '0');
            if(age > 60) count++;
        }
        return count;
    }
};