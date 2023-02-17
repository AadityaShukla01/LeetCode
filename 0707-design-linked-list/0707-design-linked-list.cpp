//creating class for data structure

class Node{
    public:
    int val;
    Node*next;
    Node(int val){
        this->val=val;
        next=NULL;
    }
};


class MyLinkedList {
public:
//intitlaising my data structure
    
    Node*head=new Node(0);
    int size=0;
    MyLinkedList() {
        
    }
    
    int get(int index) {
        if(index>=size)
        return -1;
        Node*pt=head->next;
        for(int i=0;i<index;i++){
            pt=pt->next;
        }
        return pt->val;
    }
    
    void addAtHead(int val) {
        Node*top=head->next;
        head->next=new Node(val);
        head->next->next=top;
        size++;
    }
    
    void addAtTail(int val) {
        Node*ptr=head;
        while(ptr->next)
        ptr=ptr->next;

        ptr->next=new Node(val);
    
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index>size)
        return;

        Node*ptr=head;
        for(int i=0;i<index;i++){
            ptr=ptr->next;
        }
        Node*temp=ptr->next;
        ptr->next=new Node(val);
        ptr->next->next=temp;
        size++;
    }
    
    void deleteAtIndex(int index) {

        //base case
        if(index>=size)
        return ;
        int i=0;
        Node*ptr=head;
        while(i<index){
            i++;
            ptr=ptr->next;
        }
        ptr->next=ptr->next->next;

        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */