/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution { 
public: 
    Node* copyRandomList(Node* head) { 
        unordered_map<Node*, Node*>map;
        Node* curr = head;
        //form a mapping of original node to copy
        while(curr){
            Node* copy = new Node(curr->val);
            map[curr] = copy;
            curr = curr->next;
        }

        //form links between next & random
        curr = head;
        while(curr){
            map[curr]->next = map[curr->next];
            map[curr]->random = map[curr->random];

            curr = curr->next;
        }
        return map[head];
    }
};