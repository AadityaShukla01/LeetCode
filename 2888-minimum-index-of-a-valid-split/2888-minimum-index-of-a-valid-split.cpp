class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int index = -1;
        int n = nums.size();
        int maxF = 0, maxElement;
        map<int, int>mp;
        for(auto el: nums) mp[el]++;
        for(auto it: mp)
        {
            if(it.second > maxF)
            {
                maxF = it.second;
                maxElement = it.first;
            }
        }
        int curr = 0;
        for(int i=0; i<n; i++)
        {
            if(nums[i] == maxElement) curr++;

            if(curr > (i + 1) / 2 && (maxF - curr) > (n - i - 1) / 2)
                return i;
        }
        return -1;
    }
};