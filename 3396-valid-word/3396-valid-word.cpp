class Solution {
public:
    bool isValid(string word) {
        if(word.size() < 3) return false;
        bool hasVowel = false, hasConsonant = false;

        for(auto c: word){
            if(isalnum(c)){
                if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
                    hasVowel =  true;
                }
                else if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
                    hasVowel =  true;
                }
                else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
                    hasConsonant = true;
                }
            }
            else return false;
        }
        return hasVowel && hasConsonant;
    }
};