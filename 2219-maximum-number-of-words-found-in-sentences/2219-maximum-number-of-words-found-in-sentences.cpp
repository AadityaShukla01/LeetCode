class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int n = sentences.size();
        int maxCount = 0;
        for(int i=0; i<n; i++)
        {
            stringstream s(sentences[i]);
            string str;
            int cnt = 0;
            while(s >> str) cnt++;

            maxCount = max(maxCount, cnt);
        }
        return maxCount;
    }
};