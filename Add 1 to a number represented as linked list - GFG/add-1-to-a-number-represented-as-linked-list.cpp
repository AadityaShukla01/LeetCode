//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data%10; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* reverseLL(Node* root){
        if(root == NULL) return root;
        
        Node* curr = root;
        Node* pre = NULL;
        Node* forw = NULL;
        
        while(curr){
            forw = curr->next;
            curr->next = pre;
            pre = curr;
            curr = forw;
        }
        return pre;
    }
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        Node* p = reverseLL(head);
        Node* q = new Node(1);
        Node* ans = new Node(0);
        Node* curr = ans;
        int carry=0;
        while(p || q){
            int x,y;
            if(p == NULL)
                x = 0;
            else 
                x=p->data;

            if(q == NULL)
                y = 0;
            else 
                y =q->data;
            int sum = carry + x + y;
            carry=sum/10;
            curr->next = new Node(sum%10);
            curr = curr->next;

            if(p)
                p = p->next;
            if(q)
                q = q->next;
        }
        if(carry)
            curr->next = new Node(carry);
        
        ans->next = reverseLL(ans->next);
        return ans->next;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends