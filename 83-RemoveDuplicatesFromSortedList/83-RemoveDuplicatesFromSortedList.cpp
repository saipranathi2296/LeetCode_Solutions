// Last updated: 7/6/2026, 12:11:01 PM
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr= head;
        if(head==NULL|| head->next==NULL)
        {
            return head;
        }
        while(curr!=NULL && curr->next!=NULL)
        {
            if(curr->val==curr->next->val)
            {
                ListNode* front=curr->next;
                curr->next=front->next;
                delete front;
            }
            else
            {
                curr=curr->next;
            }
        }
        return head;
    }
};