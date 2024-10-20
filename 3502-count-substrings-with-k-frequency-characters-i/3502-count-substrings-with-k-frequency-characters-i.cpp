class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int n = s.size();
        long long cnt = 0;

        vector<vector<int>>v(n, vector<int>(26, 0));

        v[0][s[0] - 'a'] = 1;
        for(int i=1; i<n; i++)
        {
            v[i][s[i] - 'a'] = 1;

            for(int in=0; in<26; in++)
            {
                v[i][in] += v[i - 1][in];
            } 
        }

        for(int i=0; i<n; i++)
        {
            for(int j=i+k-1; j<n; j++)
            {
                
                int r = j;
                int l = i;

                for(int in=0; in<26; in++)
                {
                    if(l == 0)
                    {
                        if(v[r][in] >= k){
                            cnt++;
                            break;
                        }
                    }
                    else{
                        if(v[r][in] - v[l - 1][in] >= k){
                            cnt++;
                            break;
                        }
                    }
                }
            }
        }
        return cnt;
    }
};