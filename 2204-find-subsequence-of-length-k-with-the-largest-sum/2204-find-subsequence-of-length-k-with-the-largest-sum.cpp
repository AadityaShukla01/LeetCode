class Solution {
public:
    typedef pair<int,int>P;
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<P, vector<P>, greater<P>> pq;

        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});
            if(pq.size() > k) pq.pop();
        }
        
        vector<int>temp, ans;
        while(pq.empty() == false){
            temp.push_back(pq.top().second);
            pq.pop();
        }

        sort(temp.begin(), temp.end());

        for(auto el: temp){
            ans.push_back(nums[el]);
        }
        return ans;
    }
};