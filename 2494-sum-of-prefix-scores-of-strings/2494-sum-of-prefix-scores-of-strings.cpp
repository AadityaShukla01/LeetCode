
class TrieNode{
public:
    TrieNode* child[26];
    int cnt;
};

class Solution {
public:
    TrieNode* root;
    void insert(string &s)
    {
        TrieNode* temp = root;

        for(auto c: s)
        {
            if(temp->child[c - 'a'] == NULL) temp->child[c - 'a'] = new TrieNode();
            temp = temp->child[c - 'a'];
            (temp->cnt) += 1;
        }
    }
    int score(string &s)
    {
        int cnt = 0;
        TrieNode* temp = root;
        for(auto c: s)
        {
            if(temp->child[c - 'a'])
            {
                temp = temp->child[c - 'a'];
                cnt += temp->cnt;
            }
            else break;
        }
        return cnt;
    }
    vector<int> sumPrefixScores(vector<string>& w) {
        int n = w.size();
        root = new TrieNode();
        vector<int>ans(n, 0);
        for(auto s: w) insert(s);
        for(int i=0; i<n; i++)
        {
            ans[i] = score(w[i]);
        }
        return ans;
    }
};