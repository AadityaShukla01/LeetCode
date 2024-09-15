class TrieNode {
public:
    TrieNode* child[26];
};

class Solution {
public:
    TrieNode* root;
    // prefix searching  -> trie (high probability)
    void insert(string& s) {
        TrieNode* temp = root;

        for (auto c : s) {
            if (temp->child[c - 'a'] == NULL)
                temp->child[c - 'a'] = new TrieNode();
            temp = temp->child[c - 'a'];
        }
    }
    int dp[100001];
    int sol(int i, int n, string& s) {
        if (i >= n)
            return 0;
        if(dp[i] != -1) return dp[i];
        TrieNode* temp = root;
        int ans = 1e9;
        int j = i;
        while(j < n && temp->child[s[j] - 'a'])
        {
            ans = min(ans, sol(j + 1, n, s) + 1);
            temp = temp->child[s[j] - 'a'];
            j++;
        }
        return dp[i] = ans;
    }   

    int minValidStrings(vector<string>& words, string target) {
        root = new TrieNode();
        memset(dp, -1, sizeof(dp));
        for (auto w : words)
            insert(w);
        int n = target.size();
        int ans = sol(0, n, target);
        if (ans >= 1e9)
            return -1;
        return ans;
    }
};