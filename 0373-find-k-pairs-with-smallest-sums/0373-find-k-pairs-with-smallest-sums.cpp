class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
         priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>> pq;
        set<pair<int,int>> vis;
        pq.push({nums1[0] + nums2[0],{0,0}});
        vis.insert({0,0});

        vector<vector<int>>ans;
        while(k-- && pq.empty() == false){
            int sum =  pq.top().first;
            int num1 = pq.top().second.first;
            int num2 = pq.top().second.second;
            pq.pop();
            
            ans.push_back({nums1[num1] , nums2[num2]});
            if(vis.find({num1 + 1,num2}) == vis.end() && num1+1 < nums1.size()){
                vis.insert({num1 + 1,num2});
                pq.push({nums1[num1 + 1] + nums2[num2],{num1 + 1,num2}});
            }
            if(vis.find({num1,num2 + 1}) == vis.end() && num2 + 1 < nums2.size()){
                vis.insert({num1 , num2 + 1});
                pq.push({nums1[num1] + nums2[num2 + 1],{num1,num2 + 1}});
            }
        }
        return ans;
    }
};