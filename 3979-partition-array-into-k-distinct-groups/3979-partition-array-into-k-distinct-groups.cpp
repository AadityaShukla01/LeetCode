class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(n % k) return false;

        map<int, int>mp;
        for(auto el: nums)  mp[el]++;

        priority_queue<pair<int, int>>pq;

        for(auto it: mp){
            pq.push({it.second, it.first});
        }

        while(pq.size() >= k){
            int temp = k;
            vector<pair<int, int>>v;
            while(temp--){
                auto it = pq.top();
                pq.pop();

                if(it.first - 1){
                    v.push_back({it.first - 1, it.second});
                }
            }

            for(auto it: v) pq.push(it);
        }

        return pq.size() == 0;
    }
};