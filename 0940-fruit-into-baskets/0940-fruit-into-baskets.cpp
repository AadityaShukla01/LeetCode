class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> set;
        int i = 0;
        int j = 0;
        int ans = 0;
        while (i < fruits.size() && j < fruits.size()) {

            set[fruits[i]]++;

            if (set.size() > 2) {
                while (set.size() > 2) {
                    set[fruits[j]]--;
                    if (set[fruits[j]] == 0)
                        set.erase(fruits[j]);
                    j++;
                }
            }
            ans = max(ans, i - j + 1);
            i++;
        }
        return ans;
    }
};