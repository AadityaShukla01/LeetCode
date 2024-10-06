class Solution {
public:
    string getBinary(int num)
    {
        bitset<32>bs(num);
        bool f = 0;
        string res = "";
        for(int i=31; i>=0; i--)
        {
            if(bs[i]){
                res += to_string(bs[i]);
                f = 1;
            }
            else if(f) res += to_string(bs[i]);
        }
        return res;
    }
    int getNum(string &s)
    {
        int j = s.size() - 1;
        int n = s.size();
        int num = 0;
        while(j >= 0)
        {
            if(s[j] == '1') num += pow(2, n - 1 - j);
            j--;
        }
        return num;
    }
    int maxGoodNumber(vector<int>& nums) {
        int n = nums.size();
        int mx = 0;
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                for(int k=0; k<3; k++)
                {
                    if(i!=j && j!=k && i!=k)
                    {
                        string s = getBinary(nums[i]) + getBinary(nums[j]) + getBinary(nums[k]);
                        mx = max(mx, getNum(s)) ;
                    }
                }
            }
        }
        return mx;
    }
};