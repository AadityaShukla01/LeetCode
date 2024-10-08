class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        int cnt = 0;
        int open = 0;

        for(int i=0; i<n; i++)
        {
            if(s[i] == '[') open++;
            else if(s[i] == ']' && open){
                open--;
                cnt += 2;
            }
        }

        int close = (n - cnt)/2;

        return close % 2 ? (close + 1)/2 : close/2;
    }
};