// Last updated: 7/6/2026, 12:09:45 PM
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* temp = head;
        ListNode* prevNode = nullptr;

        while (temp != nullptr) {
            if (temp->val == val) {
                // If the node to delete is the head
                if (temp == head) {
                    head = head->next;
                }

                // Re-link previous node to skip current node
                if (prevNode != nullptr) {
                    prevNode->next = temp->next;
                }

                // Move to next node and free current node
                ListNode* nextNode = temp->next;
                delete temp;
                temp = nextNode;
            } else {
                // Move prevNode and temp forward if no deletion
                prevNode = temp;
                temp = temp->next;
            }
        }

        return head;
    }
};
