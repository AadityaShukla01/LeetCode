class Solution {
public:
    int setBits(int num){
        int cnt = 0;

        for(int i=0; i<=30; i++){
            if(num & (1 << i)) cnt++;
        }
        return cnt;
    }
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        multiset<int>set;
        vector<int>ans;
        int i = 0;
        while(i < n){
            int bits = setBits(nums[i]);

            while(i < n && bits == setBits(nums[i])){
                set.insert(nums[i++]);
            }

            while(set.empty() == false){
                ans.push_back(*set.begin());
                set.erase(set.begin());
            }
        }
        sort(nums.begin(), nums.end());
        // for(auto el: ans) cout << el << " ";
        return ans == nums;
    }
};