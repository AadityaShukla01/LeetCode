class Solution {
public:
    string toLowerCase(string hahaha) {
        int n = hahaha.size();
        for(int i=0; i<n; i++)
        {
            if(isalpha(hahaha[i]) && hahaha[i] < 'a') hahaha[i] += 32;
        }
        return hahaha;
    }
};