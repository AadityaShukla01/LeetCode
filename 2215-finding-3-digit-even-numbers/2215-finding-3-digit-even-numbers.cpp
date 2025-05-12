class Solution {
public:
    set<int> res;
    void sol(vector<int>& vis, vector<int>& digits, string& num, int n) {
        if (num.size() == 3) {
            if (stoi(num) % 2 == 0)
                res.insert(stoi(num));
            return;
        }

        for (int j = 0; j < n; j++) {
            if (!vis[j]) {
                if (digits[j] == 0 && num.size() == 0)
                    continue;
                if (num.size() == 2 && digits[j] % 2)
                    continue;
                vis[j] = 1;
                num += to_string(digits[j]);
                sol(vis, digits, num, n);
                num.pop_back();
                vis[j] = 0;
            }
        }
    }
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<int> vis(n, 0);
        string num = "";
        sol(vis, digits, num, n);
        vector<int> ans;
        for (auto el : res)
            ans.push_back(el);
        return ans;
    }
};