class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        int n = order.size(), m = friends.size();
        map<int,int>mp;

        for(int i=0; i<n; i++) mp[order[i]] = i;

        vector<pair<int, int>>v;

        for(int i=0; i<m; i++){
            v.push_back({mp[friends[i]], friends[i]});
        }

        sort(v.begin(), v.end());

        vector<int>ans;

        for(auto p: v) ans.push_back(p.second);
        return ans;
    }
};