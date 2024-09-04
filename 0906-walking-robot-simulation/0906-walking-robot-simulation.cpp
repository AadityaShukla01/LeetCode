class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int n = commands.size();
        set<pair<int, int>> set;

        for (auto el : obstacles) {
            set.insert({el[0], el[1]});
        }

        int dir = 0, ans = 0;
        int x = 0, y = 0;
        for (int i = 0; i < n; i++) {
            if (commands[i] == -2) {
                dir = (dir - 1 + 4) % 4;
            } 
            else if (commands[i] == -1) {
                dir = (dir + 1) % 4;
            } 
            else {
                if (dir == 0) {
                    bool f = 0;
                    for (int j = 1; j <= commands[i]; j++) {
                        if (set.find({x, y + j}) != set.end()) {
                            y = y + j - 1;
                            f = 1;
                            break;
                        }
                    }
                    if (!f)
                        y = y + commands[i];
                } 
                else if (dir == 1) {
                    bool f = 0;
                    for (int j = 1; j <= commands[i]; j++) {
                        if (set.find({x + j, y}) != set.end()) {
                            x = x + j - 1;
                            f = 1;
                            break;
                        }
                    }
                    if (!f)
                        x = x + commands[i];
                } 
                else if (dir == 2) {
                    bool f = 0;
                    for (int j = 1; j <= commands[i]; j++) {
                        if (set.find({x, y - j}) != set.end()) {
                            y = y - j + 1;
                            f = 1;
                            break;
                        }
                    }
                    if (!f)
                        y = y - commands[i];
                } 
                else {
                    bool f = 0;
                    for (int j = 1; j <= commands[i]; j++) {
                        if (set.find({x - j, y}) != set.end()) {
                            x = x - j + 1;
                            f = 1;
                            break;
                        }
                    }
                    if (!f)
                        x = x - commands[i];
                }
            }
            ans = max(ans, x * x + y * y);
        }
        return ans;
    }
};