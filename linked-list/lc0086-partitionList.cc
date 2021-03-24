class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode ldummy(-1), rdummy(-1);
        ListNode *left = &ldummy, *right = &rdummy;
        while (head) {
            if (head->val < x)
                left = left->next = cur;
            else
                right = right->next = cur;

            head = head->next;
        }
        left->next = rdummy.next;
        right->next = nullptr;
        return ldummy.next;
    }
};
