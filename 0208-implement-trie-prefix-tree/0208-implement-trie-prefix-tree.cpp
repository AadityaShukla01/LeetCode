
class TrieNode {
public:
    bool isLast;
    TrieNode* child[26];
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        // initialising
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* temp = root;
        for(auto c: word){
            if(temp->child[c - 'a'] == NULL)
                temp->child[c - 'a'] = new TrieNode();
            temp = temp->child[c - 'a'];
        }

        temp->isLast = true;
        return ;
    }

    bool search(string word) {
        TrieNode* temp = root;
        
        for(auto c: word){
            if(temp->child[c - 'a'] == NULL)
                return false;

            temp = temp->child[c - 'a'];
        }
        return temp->isLast;
    }

    bool startsWith(string prefix) {
        TrieNode* temp = root;
        for (auto it : prefix) {
            if (temp->child[it - 'a'])
                temp = temp->child[it - 'a'];
            else
                return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */