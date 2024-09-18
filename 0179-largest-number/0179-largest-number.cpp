class Solution {
public:
    static bool comp(int a, int b)
    {
        string aa = to_string(a), bb = to_string(b);

        string one = aa + bb;
        string two = bb + aa;

        return one > two;
    }
    string largestNumber(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end(), comp);

        string ans = "";
        int zeros = 0;
        bool starting = true;
        for(auto el: nums){
            if(el == 0) zeros++;
            else starting = false;
            if(zeros <= 1 && starting)
                ans += to_string(el);
            else if(!starting)
                ans += to_string(el);
        }
        return ans;
    }
};