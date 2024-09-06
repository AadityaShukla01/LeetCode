class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {

        int sum_m = 0;
        for(auto el: rolls) sum_m += el;
        int m = rolls.size();
        int sum_n = mean * (n + m) - sum_m;

        int min_el = sum_n/n;

        if(min_el < 0 || min_el > 6 || min_el == 0) return {};
        if(sum_n % n == 0) {
            vector<int>ans(n, min_el);
            return ans;
        }
        else{
            vector<int>ans(n, min_el);
            int rem = sum_n % n;
            for(int i=0; i<n && rem; i++)
            {
                ans[i % n] += 1;
                rem--;
            }
            int mn = *min_element(ans.begin(), ans.end());
            int mx = *max_element(ans.begin(), ans.end());

            if(mn == 0 || mx > 6) return {};
            return ans;
        }
    }
};