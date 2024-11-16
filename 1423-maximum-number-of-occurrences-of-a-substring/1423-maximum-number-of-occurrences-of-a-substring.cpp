class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int mx = 0;
        map<char, int>mp1;
        map<string, int>mp2;
        int n = s.size();
        int i = 0, j = 0;
        vector<vector<int>>v(n, vector<int>(27, 0));
        while(i < n)
        {
            mp1[s[i]]++;

            if(mp1.size() > maxLetters)
            {
                while(mp1.size() > maxLetters){
                    mp1[s[j]]--;
                    if(mp1[s[j]] == 0)
                        mp1.erase(s[j]);
                    j++;
                }
            }
            
            for(int l=j; l<=i; l++)
            {
                for(int k=l; k<=i; k++)
                {
                    if( k - l  + 1>= minSize && k - l  + 1<= maxSize && v[l][k - l + 1] == 0){
                        string t = s.substr(l, k - l + 1);
                        // cout << t << "\n";
                        mp2[t]++;
                        mx = max(mx, mp2[t]);
                        v[l][k - l + 1] = 1;
                    }
                }
            }

            i++;
        }
        return mx;
    }
};