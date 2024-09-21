

class TrieNode{
public:
    TrieNode* child[10];
    bool isLast;
    int num;
};


class Solution {
public:
    TrieNode* root;
    vector<int>ans;
    void insert(int num)
    {
        string n = to_string(num);
        TrieNode* temp = root;
        for(auto c: n)
        {
            if(temp->child[c - '0'] == NULL)
                temp->child[c - '0'] = new TrieNode();
            temp = temp->child[c - '0'];
        }
        temp->isLast = true;
        temp->num = num;
    }
    void getResults(TrieNode* temp)
    {
        if(temp->isLast)
        {
            ans.push_back(temp->num);
        }

        for(int i=0; i<=9; i++)
        {
            if(temp->child[i])
                getResults(temp->child[i]);
        }
    }
    vector<int> lexicalOrder(int n) {
        root = new TrieNode();

        for(int i=1; i<=n; i++)
        {
            insert(i);
        }

        getResults(root);

        return ans;
    }
};