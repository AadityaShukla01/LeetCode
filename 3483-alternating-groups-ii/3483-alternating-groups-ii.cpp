class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        for (int i = 0; i < k - 1; i++)
            colors.push_back(colors[i]);
        colors.push_back(colors[colors.size() - 1]);
        int start = -1;

        int cnt = 0;
        // 0 1 1 0 1
        for (int i = 0; i < colors.size() - 1; i++) {
            
            if (start != -1 && i - start + 1 >= k)
                    cnt++;
            if (colors[i] != colors[i + 1]) {
                if (start == -1)
                    start = i;
               
            } else
                start = -1;
        }
        return cnt;
    }
};