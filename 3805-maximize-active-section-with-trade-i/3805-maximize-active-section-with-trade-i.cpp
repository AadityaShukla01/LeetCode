class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int mx = 0, ones = 0, cnt = 0;
        int n = s.size();
        for(auto it: s) 
        {
            if(it == '1') ones++;
        }

        for(int i=0; i<n; i++)
        {
            if(s[i] == '1')
            {
                if(i - 1 >= 0 && s[i - 1] == '0')
                {
                    int j = i;
                    cnt = 0;
                    j--;
                    while(j >= 0 && s[j] == '0')
                    {
                        cnt++;
                        j--;
                    }
                    j = i; 
                    while(j < n && s[j] == '1') j++;
                    if(j != n)
                    {
                        while(j < n && s[j] == '0'){
                            cnt++;
                            j++;
                        }
                    }
                    else cnt = 0;
                    i = j - 1;
                    mx = max(mx, cnt);
                }
            }
        }
        return mx + ones;
    }
};