class Solution {
public:
    // 递归实现
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode *next = head->next;
        head->next = swapPairs(head->next->next);
        next->next = head;
        return next;
    }

    // 迭代实现
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode dummy(-1);
        dummy.next = head;

        ListNode *prev = &dummy, *cur = head;
        while (cur->next && cur->next->next) {
            ListNode *next = cur->next;
            cur->next = next->next;
            next->next = prev->next;
            prev->next = next;
            prev = cur;
            cur = next;
        }
        return dummy.next;
    }
};
