// Last updated: 7/6/2026, 12:09:30 PM
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

ListNode* reverse(ListNode*head)
{
  ListNode*curr=head;
  ListNode*prev=NULL;
  while(curr!=NULL)
  {
    ListNode*next=curr->next;
    curr->next=prev;
    prev=curr;
    curr=next;

  }
  return prev;

}
ListNode*copylist(ListNode*head)
{
    ListNode*newnode=new ListNode(head->val);
    ListNode*tail=newnode;
    head=head->next;
    while(head)
    {
        tail->next=new ListNode(head->val);
        tail=tail->next;
        head=head->next;
    }
return newnode;

    }
    bool isPalindrome(ListNode* head) {
        ListNode* temp=copylist(head);
        ListNode* curr=reverse(head);
        while(temp!=nullptr && curr!=nullptr)
        {
            if(temp->val!=curr->val)
            {
                return false;
            }
            temp=temp->next;
            curr=curr->next;
        }
        return true;
    }
};