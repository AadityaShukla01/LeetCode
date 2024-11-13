

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int fn1(int num, int s, vector<int> &nums, int lower, int upper)
    {
        int e = nums.size() - 1;
        int ans = -1;
        while (s <= e)
        {
            int m = s + (e - s) / 2;

            if (nums[m] + num >= lower)
            {
                ans = m;
                e = m - 1;
            }
            else
            {
                s = m + 1;
            }
        }
        return ans;
    }
    int fn2(int num, int s, vector<int> &nums, int lower, int upper)
    {
        int e = nums.size() - 1;
        int ans = -1;
        while (s <= e)
        {
            int m = s + (e - s) / 2;

            if (nums[m] + num <= upper)
            {
                ans = m;
                s = m + 1;
            }
            else
            {
                e = m - 1;
            }
        }
        return ans;
    }
    long long countFairPairs(vector<int> &nums, int lower, int upper)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long cnt = 0;
        // 0 1 4 4 5 7
        for (int i = 0; i < n; i++)
        {
            int l = fn1(nums[i], i + 1, nums, lower, upper);
            int r = fn2(nums[i], i + 1, nums, lower, upper);
            if (l == -1 || r == -1)
                continue;
            // cout << r << " " << l << "\n";
            cnt += r - l + 1;
        }
        return cnt;
    }
};