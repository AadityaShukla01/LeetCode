class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        multiset<int>ms;
        int n = nums.size();
        long long cnt = 0;
        int i = 0,  j = 0;

        while(i < n){
            ms.insert(nums[i]);

            if(*ms.rbegin() - *ms.begin() > 2)
            {
                while(*ms.rbegin() - *ms.begin() > 2)
                {
                    ms.erase(ms.find(nums[j]));
                    j++;
                }
            } 

            cnt += (i - j + 1);
            i++;  
        }
        return cnt;
    }
};