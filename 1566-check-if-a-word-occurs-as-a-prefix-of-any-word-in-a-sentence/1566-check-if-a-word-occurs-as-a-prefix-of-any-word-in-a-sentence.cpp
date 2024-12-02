class Solution {
public:
    int isPrefixOfWord(string sentence, string tar) {
        stringstream ss(sentence);

        string str;
        int cnt = 1;
        while(ss >> str)
        {
            if(str.substr(0, tar.size()) == tar)
                return cnt;

            cnt++;
        }
        return -1;
    }
};