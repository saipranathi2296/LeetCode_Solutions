// Last updated: 7/6/2026, 12:11:20 PM
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if (head == NULL || head->next == NULL || k == 0)
            return head;

        // 1️⃣ Find length and tail
        ListNode* tail = head;
        int len = 1;
        while (tail->next != NULL) {
            tail = tail->next;
            len++;
        }

        // 2️⃣ Optimize k
        k = k % len;
        if (k == 0) return head;

        // 3️⃣ Make circular list
        tail->next = head;

        // 4️⃣ Find new tail (len - k - 1 steps)
        ListNode* newTail = head;
        for (int i = 1; i < len - k; i++) {
            newTail = newTail->next;
        }

        // 5️⃣ Break the circle
        ListNode* newHead = newTail->next;
        newTail->next = NULL;

        return newHead;
    }
};
