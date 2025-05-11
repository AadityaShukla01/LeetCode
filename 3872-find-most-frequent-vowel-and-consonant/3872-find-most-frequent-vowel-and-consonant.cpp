class Solution {
public:
    int maxFreqSum(string s) {
        map<char, bool> isVowel;
        isVowel['a'] = true;
        isVowel['e'] = true;
        isVowel['i'] = true;
        isVowel['o'] = true;
        isVowel['u'] = true;

        int maxVowelFreq = 0, maxConsonantFreq = 0;

        map<char, int> freq;
        
        for (auto c : s) {
            if (isVowel[c]) {
                freq[c]++;
                maxVowelFreq = max(maxVowelFreq, freq[c]);
            } else {
                freq[c]++;
                maxConsonantFreq = max(maxConsonantFreq, freq[c]);
            }
        }
        return maxConsonantFreq + maxVowelFreq;
    }
};