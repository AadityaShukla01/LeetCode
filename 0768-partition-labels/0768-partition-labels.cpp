class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        map<char, int>mp;
        for(int i=0; i<n; i++) mp[s[i]] = i;

        vector<int>ans;
        int pre = -1;
        int mx = 0;
        for(int i=0; i<n; i++)
        {
            mx = max(mx, mp[s[i]]);
            if(i == mx)
            {
                ans.push_back(i - pre);
                pre = i;
            }
        }
        return ans;
    }
};