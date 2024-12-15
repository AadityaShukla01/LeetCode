class Solution {
public:
    map<string, vector<pair<string, double>>>mp1, mp2;
    
    double mx;
    void sol(string &initialCurrency, string currency, double ans, bool sec, set<string>vis1, set<string>vis2)
    {
        if(sec) vis2.insert(currency);
        else vis1.insert(currency);

        if(currency == initialCurrency)
        {
            mx = max(mx, ans);
        }
        if(!sec)
        {

            for(auto curr: mp1[currency])
            {
                if(vis1.find(curr.first) == vis1.end())
                    sol(initialCurrency, curr.first, ans * curr.second, sec, vis1, vis2);
            }
        }

        for(auto curr: mp2[currency])
        {
            if(vis2.find(curr.first) == vis2.end())
                sol(initialCurrency, curr.first, ans * curr.second, true, vis1, vis2);
        }
    }
    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
        double ans = 1;
        mx = -1;
        int n = pairs1.size(), m = pairs2.size();
        for(int i=0; i<pairs1.size(); i++)
        {
            string l = pairs1[i][0];
            string r = pairs1[i][1];

            mp1[l].push_back({r, rates1[i]});
            mp1[r].push_back({l, 1.0 / rates1[i]});
        }

        for(int i=0; i<pairs2.size(); i++)
        {
            string l = pairs2[i][0];
            string r = pairs2[i][1];

            mp2[l].push_back({r, rates2[i]});
            mp2[r].push_back({l, 1.0 / rates2[i]});
        }
        set<string>vis1, vis2;
        sol(initialCurrency, initialCurrency, ans, false, vis1, vis2);

        return mx;
    }
};