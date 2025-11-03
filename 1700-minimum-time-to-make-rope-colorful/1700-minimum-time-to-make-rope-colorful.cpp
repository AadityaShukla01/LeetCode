class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int cost = 0;
        int n = colors.size();
        for (int i = 0; i < n; i++) {
            if (i + 1 < n && colors[i] == colors[i + 1]) {
                char color = colors[i];
                int mx = 0;
                int sum = 0;
                while (i < n && colors[i] == color) {
                    sum += neededTime[i];
                    mx = max(mx, neededTime[i]);
                    i++;
                }
                i--;
                cost += sum - mx;
            }
        }
        return cost;
    }
};