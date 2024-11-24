class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        int n = s.size();
        int individual_len = n/k;
        map<string, int>mp;
        for(int i=0; i<n; i++)
        {
            int j = i;
            string temp = "";
            while(j < i + individual_len){
                temp += s[j];
                j++;
            }
            mp[temp]++;
            i = j - 1;
        }


        for(int i=0; i<n; i++)
        {
            int j = i;
            string temp = "";
            while(j < i + individual_len){
                temp += t[j];
                j++;
            }
            if(!mp[temp]) return false;
            i = j - 1;
            mp[temp]--;
        }
        return true;
    }
};