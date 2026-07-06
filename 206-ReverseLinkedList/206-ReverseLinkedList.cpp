// Last updated: 7/6/2026, 12:09:44 PM
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {
            ListNode* temp = curr->next; // save next
            curr->next = prev;           // reverse link
            prev = curr;                 // move prev
            curr = temp;                 //
        }

        return prev; // new head
    }
};
