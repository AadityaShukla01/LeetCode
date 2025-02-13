class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>>pq;
        for(auto el: nums) pq.push(el);
        int count = 0;
        while(pq.size() > 1)
        {

            long long num1 = pq.top();
            pq.pop();
            long long num2 = pq.top();
            pq.pop();

            if(min(num1, num2) >= k) return count;

            count++;

            pq.push({1LL * min(num1, num2) * 2 + max(num1, num2)});
        }
        return pq.top() >= k ? count : -1;
    }
};