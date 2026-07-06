// Last updated: 7/6/2026, 12:11:40 PM
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    ListNode* kthnodee(ListNode* head, int k) {
        while (head != NULL && k > 1) {
            head = head->next;
            k--;
        }
        return head;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        ListNode* prevnode = NULL;

        while (curr != NULL) {
            ListNode* kthnode = kthnodee(curr, k);
            if (kthnode == NULL) {
                if (prevnode) prevnode->next = curr;
                break;
            }

            ListNode* next = kthnode->next;
            kthnode->next = NULL;

            ListNode* newHead = reverseList(curr);

            if (curr == head)
                head = newHead;
            else
                prevnode->next = newHead;

            prevnode = curr;
            curr = next;
        }
        return head;
    }
};
