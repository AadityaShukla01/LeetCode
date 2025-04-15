class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        map<char, int>mp;
        for(auto c: s) mp[c]++;

        char odd = '0';
        string res = "";
        for(auto it: mp)
        {
            int f = it.second / 2;
            while(f--) res += it.first;

            if(it.second % 2){
                odd = it.first;
            } 
        }
        string curr = res;
        string newCurr = res;
        reverse(curr.begin(), curr.end());
        if(odd != '0') newCurr += odd;

        return newCurr + curr;
    }
};