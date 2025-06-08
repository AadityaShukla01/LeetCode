class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        int n = x.size();
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; i++) {
            pq.push({y[i], i});
        }
        set<int>set;

        int ans = 0;
        while(pq.empty() == false){
            auto it = pq.top();
            pq.pop();
            int idx = x[it.second];
            int val = it.first;

            if(set.find(idx) == set.end()){
                ans += val;
                set.insert(idx);
            }

            if(set.size() == 3) break;
        }

        return set.size() == 3 ? ans : -1;
    }
};