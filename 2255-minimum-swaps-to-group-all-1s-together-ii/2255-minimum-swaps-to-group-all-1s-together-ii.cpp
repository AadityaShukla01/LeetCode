class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<int>temp = nums;
        for(auto el: nums)
            temp.push_back(el);

        int n = temp.size();
        int cnt1 = 0;
        for(auto el: nums){
            if(el == 1) cnt1++;
        }
        // 0,1,1,1,0,0,1,1,0,0,1,1,1,0,0,1,1,0
        int count = 0;
        int i = 0;
        int j = 0;
        int ans = 1e9;
        while(i < n){
            if(temp[i] == 1)
                count++;
            int len = i - j + 1;

            if(len > cnt1){
                while(len > cnt1){
                    if(temp[j] == 1)
                        count--;
                    len--;
                    j++;
                }
            }
            if(len == cnt1)
                ans = min(ans, len - count);
            i++;
        }
        return ans;
    }
};