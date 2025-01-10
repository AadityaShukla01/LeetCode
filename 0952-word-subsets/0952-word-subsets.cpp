class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n = words1.size(), m = words2.size();
        map<int, int>mp1, mp2;
        vector<string>ans;
        for(auto word: words2){
            map<char, int>temp;
            for(auto c: word){
                temp[c]++;
                mp1[c] = max(temp[c], mp1[c]);
            }
        }
        for(auto w: words1){
            map<char, int>mp2;
            for(auto c: w){
                mp2[c]++;
            }
            bool f = 1;
            for(char c='a'; c<='z'; c++){
                if(mp2[c] < mp1[c]){
                    f = 0;
                    break;
                }
            }
            if(f) ans.push_back(w);
        }
        return ans;
    }
};