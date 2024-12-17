class Solution {
public:
    string repeatLimitedString(string s, int limit) {
        int n = s.size();
        priority_queue<pair<char, int>>pq;

        map<char, int>mp;
        for(auto c: s) mp[c]++;

        for(auto it: mp) pq.push({it.first, it.second});

        string ans = "";

        while(pq.empty() == false)
        {

            auto it1 = pq.top();
            pq.pop();

            int f = min(it1.second, limit);

            ans += string(f, it1.first);

            if(pq.size() && f != it1.second)
            {
                
                auto it2 = pq.top();
                pq.pop();

                ans += it2.first;

                if(it2.second - 1) pq.push({it2.first, it2.second - 1});
            }
            else if(pq.empty()) break;

            if(f < it1.second)
            {
                pq.push({it1.first, it1.second - f});
            }
        }

        return ans;
    }
};