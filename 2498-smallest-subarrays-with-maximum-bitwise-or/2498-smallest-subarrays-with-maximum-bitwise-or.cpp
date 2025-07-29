class Solution {
public:
    void add(int num, vector<int>& v) {
        for (int i = 0; i < 32; i++) {
            if (num & (1 << i))
                v[i]++;
        }
    }

    void remove(int num, vector<int>& v) {
        for (int i = 0; i < 32; i++) {
            if (num & (1 << i))
                v[i]--;
        }
    }

    int getNum(vector<int>& v) {
        int num = 0;
        for (int i = 0; i < 32; i++) {
            if (v[i])
                num |= (1 << i);
        }
        return num;
    }
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        vector<int> pf(32, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 32; j++) {
                if (nums[i] & (1 << j))
                    pf[j]++;
            }
        }
        vector<int> v(32, 0);
        add(nums[0], v);
        int i = 1, j = 0;
        while (i < n) {

            int num = getNum(v);
            int mx = getNum(pf);

            if (num == mx && j < i) {
                ans[j] = (i - j);
                remove(nums[j], pf);
                remove(nums[j], v);
                j++;
            } 
            else {
                add(nums[i], v);
                i++;
            }
        }

        while (j < n) {
            int num = getNum(v);
            int mx = getNum(pf);
            cout <<j;
            if (num == mx) {
                ans[j] = (n - j);
            }
            remove(nums[j], pf);
            remove(nums[j], v);
            j++;
        }
        return ans;
    }
};