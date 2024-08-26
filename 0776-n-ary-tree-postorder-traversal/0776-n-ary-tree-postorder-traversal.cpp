/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int>ans;
    void sol(Node* root){
        if(!root) return;

        for(Node* node : root->children){
            sol(node);
        }

        ans.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        sol(root);
        return ans;
    }
};