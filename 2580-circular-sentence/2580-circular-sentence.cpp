class Solution {
public:
    bool isCircularSentence(string sentence) {
        char pre = '~';
        stringstream ss(sentence);
        string str;

        while(ss >> str){
            int n = str.size();
            if(pre != '~' && str[0] != pre) return false;
            pre = str[n - 1];
        }

        if(pre != sentence[0])
            return false;
        return true;
    }
};