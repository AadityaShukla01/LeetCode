class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();

        map<int, int>mp;

        for(int i=0; i<k; i++)
        {
            mp[nums[i]]++;
        }

        priority_queue<pair<int, int>>pq;
        for(auto it: mp)
        {
            pq.push({it.second, it.first});
        }
        cout << pq.size();
        int l = x;
        int sum = 0;
        vector<int>ans(n - k + 1);
        int j = 0;
        while(l-- && pq.size() > 0)
        {
            sum += pq.top().second * pq.top().first;
            pq.pop();
        }
        ans[j] = sum;
        for(int i=k; i<n; i++)
        {
            mp[nums[i - k]]--;
            if(mp[nums[i - k]] == 0) mp.erase(nums[i - k]);
            mp[nums[i]]++;
            priority_queue<pair<int, int>>pq;
            for(auto it: mp)
            {
                pq.push({it.second, it.first});
            }
            l = x;
            sum = 0;
            while(l-- && pq.size() > 0)
            {
                sum += pq.top().second * pq.top().first;
                pq.pop();
            }
            ans[++j] = sum;
        }
        return ans;
    }
};