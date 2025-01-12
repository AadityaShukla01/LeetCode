class Solution {
public:
    bool canBeValid(string s, string locked) {
        // took help
        int n = s.size();
        if(n % 2) return false;
        int unpaired = 0, notLocked = 0, open = 0, close = 0;
        for (int i = 0; i < n; i++) {
            if (locked[i] == '0')
                notLocked++;
            else if (s[i] == '(')
                open++;
            else if(s[i] == ')')
                close++;

            unpaired = close - open;
            if (unpaired > notLocked)
                return false;
        }

        unpaired = 0, notLocked = 0, open = 0, close = 0;
        for (int i = n - 1; i >= 0; i--) {
        
            if (locked[i] == '0')
                notLocked++;
            else if (s[i] == '(')
                open++;
            else if(s[i] == ')')
                close++;

            unpaired = open - close;
            if (unpaired > notLocked)
                return false;
        }

        return true;
    }
};