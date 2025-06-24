class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> indexes;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] == key)
                indexes.push_back(i);
        }
        vector<int>ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < indexes.size(); j++) {
                if(abs(indexes[j] - i) <= k){
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};