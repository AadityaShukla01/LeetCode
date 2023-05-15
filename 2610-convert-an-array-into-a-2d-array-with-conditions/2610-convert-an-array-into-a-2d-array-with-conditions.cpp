class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int>map;
        for(int i=0;i<nums.size();i++)
            map[nums[i]]++;
            
        vector<vector<int>>res;
        unordered_map<int,int>temp;

        while(map.empty()==false){
            temp=map;
            vector<int>ans;
            for(auto it:temp){
                ans.push_back(it.first);
                map[it.first]--;
                if(map[it.first]<=0) map.erase(it.first);
            }
            res.push_back(ans);
        }
        return res;
    }
};