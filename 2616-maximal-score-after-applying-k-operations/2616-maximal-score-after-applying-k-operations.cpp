class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        priority_queue<int>pq;

        for(auto el: nums) pq.push(el);

        while(k--)
        {
            int num = pq.top();
            pq.pop();
            ans += num;

            if(num % 3) pq.push(num/3 + 1);
            else pq.push(num/3);
        }
        return ans;
    }
};