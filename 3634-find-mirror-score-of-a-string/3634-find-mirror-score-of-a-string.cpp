class Solution {
public:
    long long calculateScore(string s) {
        int n = s.size();
        long long ans = 0;
        map<char, multiset<int>>mp;

        for(int i=0; i<n; i++)
        {
            char mirror = char('z' - s[i] + 'a');
            
            // cout << mirror << "\n";
            if(mp[mirror].size() == 0){
                mp[s[i]].insert(i);
                continue;
            }
            int index = *(mp[mirror].rbegin());
            mp[mirror].erase(index);

            ans += abs(index - i);
        }

        return ans;
    }
};