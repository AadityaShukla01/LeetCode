class Solution {
public:
    int count(vector<int>& nums, int mi) {
        int n = nums.size();
        // 1 1 3

        int j = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            j = i;
            while (j < n && nums[j] - nums[i] <= mi) {
                j++;
            }
            ans += j - i - 1;
        }

        return ans;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        // priority_queue<vector<int>, vector<vector<int>>,
        // greater<vector<int>>>pq;

        // for(int i=0; i<n-1; i++){
        //     int diff = nums[i + 1] - nums[i];

        //     pq.push({diff, i, 1});
        // }

        // for(int i=0; i<k; i++){
        //     if(i == k - 1){
        //         return pq.top()[0];
        //     }

        //     auto it = pq.top();
        //     pq.pop();
        //     int index = it[1];
        //     int next = it[2];
        //     if(index +  next + 1 < n){
        //         int diff = nums[index + next + 1] - nums[index];

        //         pq.push({diff, index, next + 1});
        //     }
        // }
        int hi = nums[n - 1] - nums[0];
        int lo = INT_MAX;

        for (int i = 0; i < n - 1; i++) {
            lo = min(lo, nums[i + 1] - nums[i]);
        }
        int ans = -1;
        while (lo <= hi) {
            int mi = lo + (hi - lo) / 2;

            if (count(nums, mi) >= k) {
                ans = mi;
                hi = mi - 1;
            } else {
                lo = mi + 1;
            }
        }
        return ans;
    }
};