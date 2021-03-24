class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy(-1);
        dummy.next = head;

        ListNode* prev = &dummy;
        for (int i = 1; i < m; i++) {
            prev = prev->next;
        }

        ListNode* cur = prev->next;
        for (int i = m; i < n; i++) {
            ListNode* next = cur->next;
            cur->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }

        return dummy.next;
    }
};
