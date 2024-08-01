class TrieNode{
    public:
    TrieNode* child[2];
};


class Solution {
public:
    TrieNode* root;
    void insert(int num){
        TrieNode* temp = root;
        bitset<32>bs(num);
        for(int i=31; i>=0; i--){
            if(temp->child[bs[i]] == NULL)
                temp->child[bs[i]] = new TrieNode();
            temp = temp->child[bs[i]];
        }
    }
    int maxXor(int num){
        int ans = 0;
        TrieNode* temp = root;
        bitset<32>bs(num);
        for(int i=31; i>=0; i--){
            if(temp->child[!bs[i]]){
                ans = ans | (1 << i);
                temp = temp->child[!bs[i]];
            }
            else
                temp = temp->child[bs[i]];
        }
        return ans;
    }
    int findMaximumXOR(vector<int>& nums) {
        root = new TrieNode();

        int mx = -1e9;
        for(auto el: nums) insert(el);
        for(auto el: nums){
            mx = max(mx, maxXor(el));
        }
        return mx;
    }
};