class Solution {
public:
    void add(int num, map<int, int>&mp)
    {
        for(int i=0; i<32; i++) {
            if(num & (1 << i))
                mp[i]++;
        }
    }

    void remove(int num, map<int, int>&mp)
    {
        for(int i=0; i<32; i++)
        {
            if(num & (1 << i)){
                if(mp[i])
                    mp[i]--;
            }
        }
    }
    int getNum(map<int, int>&mp)
    {
        int num = 0;

        for(int i=0; i<32; i++)
        {
            if(mp[i])
                num = num | (1 << i);
        }
        return num;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int i = 0, j = 0;
        int n = nums.size();
        if(k == 0){
            return n > 0;
        }
        map<int, int>mp;
        int mn = INT_MAX;
        while(i < n)
        {
            add(nums[i], mp);

            if(getNum(mp) >= k)
            {
                while(getNum(mp) >= k)
                {
                    mn = min(mn, i - j + 1);
                    remove(nums[j], mp);
                    j++;
                }
            }
            i++;
        }
        return mn == INT_MAX ? -1 : mn;
    }
};