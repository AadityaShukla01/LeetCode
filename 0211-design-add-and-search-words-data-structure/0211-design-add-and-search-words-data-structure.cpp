
class TrieNode{
public:
    bool isLast;
    TrieNode* child[26];
};


class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* temp = root;

        for(auto c: word){
            if(temp->child[c - 'a'] == NULL)
                temp->child[c - 'a'] = new TrieNode();
            temp = temp->child[c - 'a'];
        }

        temp->isLast = true;
    }
    
    bool search(string word) {
        bool ans = false;
        int n = word.size();
        TrieNode * temp = root;
        dfs(0, word, ans, n, temp);
        return ans;
    }
    void dfs(int i, string &word, bool &ans, int n, TrieNode* temp){
        if(!temp) return;
        if(i >= n){
            if(temp->isLast) ans = true;
            return;
        }

        if(word[i] == '.'){
            for(char c='a'; c<='z'; c++){
                if(temp->child[c - 'a']){
                    dfs(i + 1, word, ans, n, temp->child[c - 'a']);
                }
            }
        }
        else{
            dfs(i + 1, word, ans, n, temp->child[word[i] - 'a']);
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */