class Solution {
public:
    ListNode* deleteDuplicatesII(ListNode* head) {
        if (head == nullptr) return head;

        ListNode dummy(-1);
        dummy.next = head;

        ListNode *cur = head, *prev = &dummy;
        while (cur) {
            while (cur->next && cur->val == cur->next->val)
                cur = cur->next;

            if (cur != prev->next)
                prev->next = cur->next;
            else
                prev = cur;

            cur = cur->next;
        }
        return dummy.next;
    }
};
