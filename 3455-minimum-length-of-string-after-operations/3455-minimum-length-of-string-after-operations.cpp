class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        vector<int>freq(26, 0);
        for(auto c: s){
            freq[c - 'a']++;
        }
        int cnt = 0;
        for(int i=0; i<26; i++){
            if(freq[i] > 2){
                while(freq[i] > 2){
                    cnt++;
                    freq[i] -= 2;
                }
            }
        }
        return n - 2*cnt;
    }
};