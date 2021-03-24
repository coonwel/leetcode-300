class Solution {
public:
    int removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(-1);
        dummy.next = head;

        ListNode *ahead = &dummy, *behind = &dummy;
        for (int i = 0; i < n; i++) {
            ahead = ahead->next;
        }

        while (ahead->next != nullptr) {
            ahead = ahead->next;
            behind = behind->next;
        }

        ListNode* tmp = behind->next;
        behind->next = behind->next->next;
        delete tmp;

        return dummy.next;
    }
};
