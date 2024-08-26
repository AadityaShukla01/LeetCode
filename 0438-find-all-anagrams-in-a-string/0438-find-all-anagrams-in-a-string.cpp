class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int cnt = p.size();
        map<char, int>mp;
        for(auto c: p) mp[c]++;
        vector<int>ans;
        int j = 0;
        for(int i=0; i<s.size(); i++){
            if(mp[s[i]] > 0) cnt--;

            mp[s[i]]--;

            if(cnt == 0){
                int start = j;
                while(cnt == 0){
                    mp[s[j]]++;
                    start = j;
                    if(mp[s[j]] > 0) cnt++;
                    j++;
                }
                cout << i - j + 1 << "\n";
                if(i - j + 2 == p.size())
                    ans.push_back(start);
            }
        }
        return ans;
    }
};