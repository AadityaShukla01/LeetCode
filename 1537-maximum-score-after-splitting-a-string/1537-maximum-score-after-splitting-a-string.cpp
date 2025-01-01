class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int ones = 0, zeros = 0;
        for(auto el: s){
            if(el == '1')
                ones++;
        }

        int mx = 0;

        for(int i=0; i<n-1; i++)
        {
            if(s[i] == '0') zeros++;
            else ones--;

            mx = max(mx, zeros + ones);
        }
        return mx;
    }
};