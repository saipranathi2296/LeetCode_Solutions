// Last updated: 7/6/2026, 12:11:49 PM
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* slow = l1;
        ListNode* fast = l2;
        slow = slow->next;
        fast = fast->next;
        int first = (l1->val + l2->val) % 10;
        ListNode* newnode = new ListNode(first);
        ListNode* tail = newnode;
        int carry = (l1->val + l2->val) / 10;
        while (slow != NULL && fast != NULL) {
            int sum = carry;
            int val = sum + slow->val + fast->val;
            tail->next = new ListNode(val % 10);
            slow = slow->next;
            fast = fast->next;
            tail = tail->next;
            carry = val / 10;
        }
        while (slow != NULL) {
            int tot = carry + slow->val;
            tail->next = new ListNode(tot%10);
            slow = slow->next;
            carry=tot/10;
            tail = tail->next;
        }
        while (fast != NULL) {
            int tot = carry + fast->val;
            tail->next = new ListNode(tot%10);
            fast = fast->next;
            tail = tail->next;
            carry=tot/10;
        }
        if(carry)
        {
            tail->next=new ListNode(carry);
            
        }
        return newnode;
    }
};