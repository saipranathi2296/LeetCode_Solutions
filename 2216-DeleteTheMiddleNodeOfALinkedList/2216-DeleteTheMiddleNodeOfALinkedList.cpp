// Last updated: 7/6/2026, 12:07:18 PM
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // Edge case: 0 or 1 node
        if (head == nullptr || head->next == nullptr)
            return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

       
        prev->next = slow->next;
        delete slow;

        return head;
    }
};
