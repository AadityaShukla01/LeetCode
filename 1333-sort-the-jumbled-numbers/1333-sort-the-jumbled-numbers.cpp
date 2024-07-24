class Solution {
public:
    static bool comp(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] < b[0];
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        map<char, char> mp;
        for (int i = 0; i < mapping.size(); i++) {
            mp[i + '0'] = mapping[i] + '0';
        }
        vector<vector<int>> v;
        int i = 0;
        for (auto el : nums) {
            string s = "";
            int num = el;
            string newNum = to_string(el);
            for(int j=0; j<newNum.size(); j++){
                char c = newNum[j];
                s += string(1, mp[c]);
            }
            v.push_back({stoi(s), i, num});
            i++;
        }
        sort(v.begin(), v.end(), comp);
        // for (auto el : v) {
        //     cout << el[0] << " " << el[1] << " " << el[2] << "\n";
        // }
        vector<int> ans;
        for (auto el : v)
            ans.push_back(el[2]);
        return ans;
    }
};