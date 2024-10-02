class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>>p;

        for(int i=0; i<n; i++) p.push_back({arr[i], i});

        sort(p.begin(), p.end());
        int r = 0;
        int pre = INT_MIN;
        for(int i=0; i<n; i++)
        {
            if(p[i].first > pre)
            {
                r++;
                arr[p[i].second] = r;
            }
            else
            {
                arr[p[i].second] = r;
            }
            pre = p[i].first;
        }
        return arr;
    }
};