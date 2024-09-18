/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void sol(Node* curr, Node* copy, vector<Node*>&vis)
    {
        vis[copy->val] = copy;

        for(auto node: curr->neighbors)
        {
            if(vis[node->val] == NULL)
            {
                Node* newNode = new Node(node->val);
                copy->neighbors.push_back(newNode);
                sol(node, newNode, vis);
            }
            else
            {
                copy->neighbors.push_back(vis[node->val]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;

        vector<Node*>vis(10001, NULL);
        Node* copy = new Node(node->val);
        sol(node, copy, vis);
        return copy;
    }
};