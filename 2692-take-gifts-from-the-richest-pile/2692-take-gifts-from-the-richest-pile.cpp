class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pq;
        int n = gifts.size();
        for(auto el: gifts) 
        {
            pq.push(el);
        }
        long long ans = 0;
        while(k--)
        {
            auto el = pq.top();
            pq.pop();

            pq.push(sqrt(el));
        }

        while(pq.empty() == false)
        {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};