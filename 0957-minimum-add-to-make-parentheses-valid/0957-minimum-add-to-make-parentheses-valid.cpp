class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        int open = 0;
        int cnt = 0;

        for(int i=0; i<n; i++)
        {
            if(s[i] == '(') open++;
            else if(s[i] == ')' && open)
            {
                cnt+=2;
                open--;
            }
        }

        return n - cnt;
    }
};