class Solution {
public:
    long long count;
    void mergeSort(int l, int r, vector<int>& nums) {
        if (l >= r)
            return;

        int mi = l + (r - l) / 2;

        mergeSort(l, mi, nums);
        mergeSort(mi + 1, r, nums);

        merge(l, mi, r, nums);
    }

    void merge(int lo, int mi, int hi, vector<int>& a) {
        vector<int> temp;
        int l = lo;
        int r = mi + 1;

        while (l <= mi && r <= hi) {
            if (1LL*a[l] > 1LL*2 * a[r]) {
                count += (mi - l + 1);
                temp.push_back(a[r]);
                r++;
            } else {
                temp.push_back(a[l]);
                l++;
            }
        }
        while (l <= mi) {
            temp.push_back(a[l]);
            l++;
        }
        while (r <= hi) {
            temp.push_back(a[r]);
            r++;
        }
        sort(temp.begin(), temp.end());
        for (int i = lo; i <= hi; i++) {
            a[i] = temp[i - lo];
        }
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();

        int l = 0;
        int r = n - 1;

        mergeSort(l, r, nums);
        // for (auto it : nums)
        //     cout << it;
        return count;
    }
};