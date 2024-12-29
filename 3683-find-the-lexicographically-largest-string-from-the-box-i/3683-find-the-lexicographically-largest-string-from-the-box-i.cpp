class Solution {
public:
    string answerString(string word, int numFriends) {
        string mx = "";
        int n = word.size();
        if(numFriends == 1) return word;

        for(int i=0; i<n; i++)
        {
            string temp = word.substr(i, n - numFriends + 1);
            
            mx = max(mx, temp);
        } 
        return mx;
    }
};