/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode*curr1=headA;
        ListNode*curr2=headB;

        while( curr1 || curr2 ){


            if(curr1==NULL)
            curr1=headB;

            if(curr2==NULL)
            curr2 = headA;
            
            if(curr1==curr2)
            return curr1;
            
            curr1=curr1->next;
            curr2=curr2->next;

        }
        return curr1;
    }
};
//   ListNode *p1 = headA;
//     ListNode *p2 = headB;
        
//     if (p1 == NULL || p2 == NULL) return NULL;

//     while (p1 != NULL && p2 != NULL && p1 != p2) {
//         p1 = p1->next;
//         p2 = p2->next;

//         //
//         // Any time they collide or reach end together without colliding 
//         // then return any one of the pointers.
//         //
//         if (p1 == p2) return p1;

//         //
//         // If one of them reaches the end earlier then reuse it 
//         // by moving it to the beginning of other list.
//         // Once both of them go through reassigning, 
//         // they will be equidistant from the collision point.
//         //
//         if (p1 == NULL) p1 = headB;
//         if (p2 == NULL) p2 = headA;
//     }
        
//     return p1;