class Solution {
public:
    typedef pair<int, int>P;
    vector<int> getOrder(vector<vector<int>>& t) {
        int n = t.size();
        vector<vector<int>>v;

        for(int i=0; i<n; i++)
        {
            v.push_back({t[i][0], t[i][1], i});
        }

        sort(v.begin(), v.end());
        vector<int>ans;
        priority_queue<P, vector<P>, greater<P>>pq;
        pq.push({v[0][1], v[0][2]});
        int i = 1;
        long long curr_time = v[0][0];
        int len = n;
        while(len--)
        {
            if(pq.size()){
                curr_time = curr_time + pq.top().first;
                ans.push_back(pq.top().second);
                pq.pop();
            }
            if(i < n && curr_time < v[i][0] && pq.empty())
            {
                curr_time = v[i][0];
                pq.push({v[i][1], v[i][2]});
                i++;
            }
            while(i < n && curr_time >= v[i][0]) 
            {
                pq.push({v[i][1], v[i][2]});
                i++;
            }
        }
        return ans;
    }
};