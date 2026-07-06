// Last updated: 7/6/2026, 12:10:16 PM
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;

        // Step 1: Detect cycle
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // Step 2: Find start of cycle
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow; // start of the cycle
            }
        }

        return nullptr; // no cycle
    }
};
