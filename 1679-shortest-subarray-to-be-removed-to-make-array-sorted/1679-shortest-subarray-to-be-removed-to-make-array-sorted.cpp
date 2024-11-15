class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();

        int l = 0;
        int r = n - 1;

        while(l + 1 < n && arr[l] <= arr[l + 1])
        {
            l++;
        }
        if(l == n - 1) return 0;

        while(r - 1 >= 0 && arr[r] >= arr[r - 1])
        {
            r--;
        }

        int i = 0, j = r;

        int mn = INT_MAX;

        mn = min(r, n - l - 1);

        while(i <= l && j < n)
        {
            if(arr[i] <= arr[j])
            {
                mn = min(mn, j - i - 1);
                i++;
            }
            else{
                j++;
            }
        }
        return mn;
    }
};