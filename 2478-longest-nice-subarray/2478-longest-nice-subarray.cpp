class Solution {
public:
    void _add(int el, vector<int>&v)
    {
        for(int i=0; i<32; i++)
        {
            if(el & (1 << i)) v[i]++;
        }
    }
    int _and(int el, vector<int>&v){
        for(int i=0; i<32; i++){
            if(el & (1 << i) && v[i]) return 1;
        }
        return 0;
    }
    void _remove(int num, vector<int>&v)
    {
        for(int i=0; i<32; i++){
            if(num & (1 << i)) v[i]--;
        }
    }
    int longestNiceSubarray(vector<int>& nums) {
        // if c & (a or b) is 0 then c &a and c & b is also 0
        int mxLen = 0;

        int cumm_or = 0;

        int i=0, j=0;
        int n = nums.size();
        vector<int>v(32, 0);
        while(i < n && j < n)
        {
            if(!_and(nums[i], v)) mxLen = max(mxLen, i - j + 1);
            while(j <= i && _and(nums[i], v)){
                _remove(nums[j], v);
                j++;
            }
            _add(nums[i], v);
            i++;
        } 
        return mxLen;
    }
};