class Solution {
public:
    //time will be O(nlogn) for sorting priority queue will be nlogk k elements ata a time
    static bool comp(const pair<int, int>&a, const pair<int, int>&b){
        if(a.second == b.second)
            return a.first > b.first;
        return a.second > b.second;
    }
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        //we will not use dp & be greedy because the time constaints dont allow us to solve this problem in DP
        vector<pair<int, int>>p;
        for(int i=0; i<n; i++){
            p.push_back({nums1[i], nums2[i]});
        }

        //sort in such a way that we get nums2 val as maximum since we are multiplying it
        priority_queue<int, vector<int>, greater<int>>pq; //min heap because we want to remove min  value from queue at a time->greedy
        sort(p.begin(), p.end(), comp);
        long long sum = 0;
        long long ans = 0;
        for(int i=0; i<n; i++){
            pq.push(p[i].first);
            sum += p[i].first;

            //write it first else we may skip ans
            if(pq.size() > k){
                sum -= pq.top();
                pq.pop();
            }
            if(pq.size() == k){
                ans = max(ans, sum * p[i].second);
            }
        }
        return ans; 
    }
};