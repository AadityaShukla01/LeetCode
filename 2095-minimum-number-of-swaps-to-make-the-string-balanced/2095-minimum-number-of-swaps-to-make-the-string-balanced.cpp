class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();

        stack<char>st;
        int cnt = 0;
        for(int i=0; i<n; i++)
        {
            if(st.empty() == false && s[i] == ']')
            {
                cnt += 2;
                st.pop();
            }
            else if(s[i] == '[') st.push(s[i]);
        }

        int open =  (n - cnt)/2;

        if(open % 2) return (open + 1)/2;

        return open/2;
    }
};