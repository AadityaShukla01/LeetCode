class Solution {
public:
    static bool comp(const pair<int, string>&a, const pair<int, string>&b){
        return a.first > b.first;
    }
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>>v;
        int n = names.size();
        for(int i=0; i<n; i++){
            v.push_back({heights[i], names[i]});
        }

        sort(v.begin(), v.end(), comp);
        vector<string>res;
        for(int i=0; i<v.size(); i++)
            res.push_back(v[i].second);
        return res;
    }
};