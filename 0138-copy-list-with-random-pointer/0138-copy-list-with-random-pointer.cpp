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
       //using extra space
    //    map<Node*,Node*>map;
    //    Node *curr=head;
    //    while(curr){
    //        map[curr]=new Node(curr->val);
    //        curr=curr->next;
    //    }
    //    curr = head;
    //    while(curr){
    //        map[curr]->next=map[curr->next];
    //        map[curr]->random=map[curr->random];
    //        curr=curr->next;
    //    }
    //    return map[head];
       //without using extra space
    Node *newHead, *l1, *l2;
    if (head == NULL) return NULL;
    for (l1 = head; l1 != NULL; l1 = l1->next->next) {
        l2 = new Node(l1->val);
        l2->next = l1->next;
        l1->next = l2;
    }
        
    newHead = head->next;
    for (l1 = head; l1 != NULL; l1 = l1->next->next) {
        if (l1->random != NULL) l1->next->random = l1->random->next;
    }
    for (l2 = head; l2 != NULL; l2 = l2->next) {
        cout<<l2->val<<endl;
    }
        
    for (l1 = head; l1 != NULL; l1 = l1->next) {
        l2 = l1->next;
        l1->next = l2->next;
        if (l2->next != NULL) l2->next = l2->next->next;
    }
    return newHead;
   }
};