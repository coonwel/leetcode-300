class Solution {
public:
    // 递归实现
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr) retun head;

        ListNode* tail = head;
        for (int i = 1; i <= k; i++) {
            if (tail == nullptr) return head;
            tail = tail->next;
        }

        ListNode* newHead = reverse(head, tail);
        head->next = reverseKGroup(tail, k);
        return newHead;
    }

    ListNode* reverse(ListNode* head, ListNode* tail) {
        if (head == tail || head->next == tail) return head;
        ListNode* newHead = reverse(head->next, tail);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k <= 1) return head;

        ListNode dummy(-1);
        dummy.next = head;

        int len = 1;
        while (head = head->next) {
            len++;
        }

        ListNode *prev = &dummy;
        for (int i = len; i >= k; i -= k) {
            ListNode *cur = prev->next;
            for (int j = 1; j < k; j++) {
                ListNode *next = cur->next;
                cur->next = next->next;
                next->next = prev->next;
                prev->next = next;
            }
            prev = cur;
        }

        return dummy.next;
    }
};
