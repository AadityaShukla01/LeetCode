class Solution {
public:
    // TOUGH PROBLEM FOR ME
    // MULTIPLICATION WILL MAXIMISE THE RESULT
    // SO SORT IN DESCENDING ORDER FOR MULTIPLICATION
    // NOW SINCE ORDER OF SUBSEQUENCE DOESNT MATTER WE REMOVE THE SMALLEST
    // ELEMENT FROM SUM (nums1) FOR KEEPING A TRACK OF SMALLEST ELEMENT WE CAN
    // USE A PRIORITY QUEUE
    // SINCE MULTPLICATION IS ALREADY SPRTED IN DESCENDIGN ORDER WE DONT NEED TO DO ANYTHING
    static bool comp(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second == b.second)
            return a.first > b.first;

        return a.second > b.second;
    }
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> p;
        for (int i = 0; i < n; i++) {
            p.push_back({nums1[i], nums2[i]});
        }

        sort(p.begin(), p.end(), comp);

        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            sum += p[i].first;
            pq.push(p[i].first);

            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            if (pq.size() == k)
                ans = max(ans, sum * p[i].second);
        }
        return ans;
    }
};