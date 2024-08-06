class Solution {
public:
    typedef pair<int, int>P;
    const int mo = 1e9 + 7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        long long ans = 0;
        priority_queue<P, vector<P>, greater<P>>pq;

        for(int i=0; i<n; i++){
            pq.push({nums[i], i});
        }

        for(int i=1; i<=right; i++){
            auto it = pq.top();
            pq.pop();

            if(i >= left){
                ans += it.first;
            }
            if(it.second + 1 < n){
                pq.push({it.first + nums[it.second + 1], it.second + 1});
            }
        }
        return ans % mo;
    }
};