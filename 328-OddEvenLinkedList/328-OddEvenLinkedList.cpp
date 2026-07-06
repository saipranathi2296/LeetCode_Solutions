// Last updated: 7/6/2026, 12:09:05 PM
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
//         ListNode* slow = head;
//         if(head==NULL) return NULL;
//         ListNode* newnode = new ListNode(head->val);
//         slow =(slow->next==NULL)?NULL: slow->next->next;
//         ListNode* tail = newnode;
//         while (slow != NULL ) {
//             tail->next = new ListNode(slow->val);
//              tail = tail->next;
//             if (slow->next!= NULL) {
//                 slow = slow->next->next;
//             } 
//             else
//             {
//                 slow=NULL;
//             }
//             }
           
        
//         ListNode* fast = head->next;

//         while (fast != NULL) {
//             tail->next = new ListNode(fast->val);
//             tail = tail->next;
//             if (fast->next!= NULL) {
//                 fast = fast->next->next;
//             }
//             else
//             {
// fast=NULL;
//             }
            
//         }
//         return newnode;
if(head == NULL || head->next == nullptr){
    return head;
}
ListNode*odd=head;
ListNode* even=head->next;
ListNode*evenhead=even;
while(even!=NULL && even->next!=NULL)
{
    odd->next=even->next;
    odd=odd->next;
    even->next=odd->next;
    even=even->next;
    

}
odd->next=evenhead;
return head;
    }
};