class Solution {
public:
    bool isAnagram(string& a, string& b) {
        vector<int> f1(26, 0), f2(26, 0);

        for (auto c : a)
            f1[c - 'a']++;
        for (auto c : b)
            f2[c - 'a']++;

        for (int i = 0; i < 26; i++) {
            if (f1[i] != f2[i])
                return false;
        }
        return true;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        vector<string>ans;
        int i = 0;

        while(i < n){
            ans.push_back(words[i]);

            while(i + 1 < n && isAnagram(words[i], words[i + 1])){
                i++;
            }
            i++;
        }
        return ans;
    }
};