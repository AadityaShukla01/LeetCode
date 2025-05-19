class Solution {
public:
    string triangleType(vector<int>& nums) {
        set<int> set;
        int a = nums[0], b = nums[1], c = nums[2];
        set.insert(a);
        set.insert(b);
        set.insert(c);

        if (a + b > c && b + c > a && a + c > b) {
            if (set.size() == 1)
                return "equilateral";
            else if (set.size() == 2)
                return "isosceles";
            return "scalene";
        }

        return "none";
    }
};