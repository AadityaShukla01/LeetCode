class Solution {
public:
    bool comp(string& a, string& b) {
        if (a.size() != b.size())
            return false;

        int cnt = 0, i = 0;
        int n = a.size();

        while (i < n) {
            if (a[i] != b[i])
                cnt++;
            i++;
        }
        return cnt == 1;
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words,
                                                vector<int>& groups) {
        int n = groups.size();
        int mxLen = 1;
        vector<int> lis(n, 1), store(n);
        int lastIndex = 0;
        for (int i = 0; i < n; i++) {
            store[i] = i;
            for (int j = 0; j < i; j++) {
                if (groups[i] != groups[j] && comp(words[i], words[j])) {
                    if (lis[i] < lis[j] + 1) {
                        lis[i] = lis[j] + 1;
                        store[i] = j;
                    }
                }
            }

            if (lis[i] > mxLen) {
                mxLen = lis[i];
                lastIndex = i;
            }
        }
        vector<string>ans;
        while(lastIndex != store[lastIndex]){
            ans.push_back(words[lastIndex]);
            lastIndex = store[lastIndex];
        }
        ans.push_back(words[lastIndex]);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};