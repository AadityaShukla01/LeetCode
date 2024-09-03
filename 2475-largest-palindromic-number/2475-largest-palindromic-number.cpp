class Solution {
public:
    string largestPalindromic(string num) {
        int n = num.size();
        map<char, int>mp;

        for(auto c: num) mp[c]++;

        vector<pair<char, int>>even, odd;

        for(auto it: mp)
        {
            if(it.second % 2) odd.push_back({it.first, it.second});
            else even.push_back({it.first, it.second});
        }
        sort(odd.begin(), odd.end());
        reverse(odd.begin(), odd.end());
        for(int i=0; i<odd.size(); i++)
        {
            even.push_back({odd[i].first, odd[i].second - 1});
        }
        sort(even.begin(), even.end());

        string ans = "";
        int sz = even.size();

        int i = 0;
        while(i < sz)
        {
            string left = "";
            int freq = even[i].second;
            int cnt = 0;
            while(cnt < freq/2) {
                left += even[i].first;
                cnt++;
            }

            ans = left + ans;
            i++;
        }

        string pre = ans;
        reverse(pre.begin(), pre.end());
        if(odd.size())
        {
            if(odd[0].second)
                ans += odd[0].first;
        }
        ans = ans + pre;
        i = 0;
        int j = ans.size() - 1;
        string res = "";
        while(i <= j && ans[i] == '0' && ans[j] == '0'){
            i++;
            j--;
        }
        if(i <= j){
            res = ans.substr(i, j - i + 1);
            return res;
        }
        return "0";
    }
};