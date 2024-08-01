
class TrieNode{
    public:
    TrieNode* child[2];
};
class Solution {
public:
    TrieNode* root;
    void insert(int num){
        bitset<32>bitset(num);
        //will represnt num in 32 bits 1 ->0...31..1
        //start from 31 since we want to maximise number
        TrieNode* temp = root;
        for(int i=31; i>=0; i--){
            if(temp->child[bitset[i]] == NULL)
                temp->child[bitset[i]] = new TrieNode();
            temp = temp->child[bitset[i]];
        }
    }
    int maxXor(int num){
        int ans = 0;
        TrieNode* temp = root;
        bitset<32>bitset(num);
        for(int i=31; i>=0; i--){
            if(temp->child[!bitset[i]]){
                temp = temp->child[!bitset[i]];
                ans = ans | (1 << i);
            }
            else{
                temp = temp->child[bitset[i]];
            }
        }
        return ans;
    }
    int findMaximumXOR(vector<int>& nums) {
        //we need to find max xor
        // 1) brute force is to find all possible ways O(n^2)
        //2) now how can we maximise xorr? we know that xorr is one when bits are opposite to each other
        //so for every number we start from MSB since we want to maximise(100 > 011) and compare prefix for every bit(32) so time complexity will be O(n*32)

        root = new TrieNode();
        for(auto it: nums){
            insert(it);
        }

        int ans = 0;
        for(int num: nums){
            ans = max(ans, maxXor(num));
        }
        return ans;
    }
};