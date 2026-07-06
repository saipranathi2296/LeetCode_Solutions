// Last updated: 7/6/2026, 12:10:08 PM
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {

      if (headA == nullptr || headB == nullptr)
            return nullptr;

        ListNode* p1 = headA;
        ListNode* p2 = headB;

        while (p1 != p2) {
            p1 = (p1 == nullptr) ? headB : p1->next;
            p2 = (p2 == nullptr) ? headA : p2->next;
        }

        return p1;
    }
};
// class Solution {
// public:
//     ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
//         unordered_set<ListNode*> s;

//         while (headA) {
//             s.insert(headA);
//             headA = headA->next;
//         }

//         while (headB) {
//             if (s.count(headB)) {
//                 return headB;
//             }
//             headB = headB->next;
//         }
//         return NULL;
//     }
// };
// class Solution {
// public:
//     ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
//         for (ListNode* a = headA; a != NULL; a = a->next) {
//             for (ListNode* b = headB; b != NULL; b = b->next) {
//                 if (a == b) {
//                     return a;
//                 }
//             }
//         }
//         return NULL;
//     }
// };
