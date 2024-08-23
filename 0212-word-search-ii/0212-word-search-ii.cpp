
struct TrieNode{
    bool isLast;
    string word;
    TrieNode* child[26];
};


class Solution {
public:
    TrieNode* root;
    void insert(string &word){
        TrieNode* temp = root;
        for(auto c: word){
            if(temp->child[c - 'a'] == NULL) temp->child[c - 'a'] = new TrieNode();
            temp = temp->child[c - 'a'];
        }


        temp->isLast = true;
        temp->word = word;
        return ;
    }
    vector<string>ans;
    set<string>s;
    void sol(int r, int c, int n, int m, vector<vector<char>>& b, TrieNode* temp){
        if(r < 0 || r >= n || c < 0 || c >= m || b[r][c] == '*' || !temp) return;


        char ch = b[r][c];

        
        

        b[r][c] = '*';

        temp = temp->child[ch - 'a'];

        if(temp && temp->isLast){
            s.insert(temp->word);
        }
        sol(r + 1, c, n, m, b, temp);
        sol(r - 1, c, n, m, b, temp);
        sol(r, c + 1, n, m, b, temp);
        sol(r, c - 1, n, m, b, temp);


        b[r][c] = ch;
    }
    vector<string> findWords(vector<vector<char>>& b, vector<string>& words) {
        root = new TrieNode();
        int n = b.size(), m = b[0].size();
        for(auto str: words) insert(str);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                TrieNode* temp = root;
                sol(i, j, n, m, b, temp);
            }
        }
        for(auto str: s) ans.push_back(str);
        return ans;
    }
};