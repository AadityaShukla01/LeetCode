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
   Node *copyRandomList(Node *head){

       map<Node*,Node*>mapper;
       Node*ptr=head;

       while(ptr){
           mapper[ptr]=new Node(ptr->val);
           ptr=ptr->next;
       }
       ptr=head;
       while(ptr){
           mapper[ptr]->next=mapper[ptr->next];
           mapper[ptr]->random=mapper[ptr->random];
           ptr=ptr->next;
       }
       return mapper[head];
   }
};