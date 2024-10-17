class Solution {
public:
    static bool cmp(const pair<char, int>&a, const pair<char, int>&b)
    {
        if(a.first == b.first) return a.second < b.second;

        return a.first > b.first;
    }
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();
        vector<pair<char, int>>p;
        for(int i=0; i<n; i++) p.push_back({s[i], i});
        sort(p.begin(), p.end(), cmp);
        string temp = s;
        for(int i=0; i<n; i++)
        {
            if(p[i].first != s[i])
            {
                int el = p[i].first;
                int j = i;
                while(j < n && el == p[j].first)
                {
                    string t = s;
                    swap(t[p[j].second], t[i]);
                    j++;
                    temp = max(temp, t);
                }
                break;
            }
        }
        return stoi(temp);
    }
};