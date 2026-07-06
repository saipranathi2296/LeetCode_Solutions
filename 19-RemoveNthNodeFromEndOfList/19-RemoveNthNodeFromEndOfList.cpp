// Last updated: 7/6/2026, 12:11:44 PM
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr) return head;
        ListNode* temp;
        int count=0;
        for(temp=head;temp!=nullptr;temp=temp->next)
        {
count++;
        }
        int pos=count-n+1;
        temp=head;
        if(pos == 1)
{
    ListNode* curr = head;
    head = head->next;
    delete curr;
    return head;
}
        for(int i=0;i<pos-2;i++)
        {
            temp=temp->next;
        }
        ListNode*curr=temp->next;
        temp->next=curr->next;
        delete curr;
        return head;
        
        
    }
};