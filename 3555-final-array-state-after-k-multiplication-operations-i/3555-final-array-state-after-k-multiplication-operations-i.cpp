class Solution {
public:
    typedef pair<int, int>P;
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();


        priority_queue<P, vector<P>, greater<P>>pq;

        for(int i=0; i<n; i++) pq.push({nums[i], i});

        while(k--)
        {
            auto it = pq.top();
            pq.pop();

            int num = it.first;
            int idx = it.second;

            nums[idx] = num * multiplier;
            pq.push({nums[idx], idx});
        }

        return nums;
    }
};