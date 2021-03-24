class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head==nullptr || head->next==nullptr) return head;

        ListNode *slow = head, *fast = head, *prev = nullptr;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;

        return merge( sortList(head),  sortList(slow));
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;

        ListNode dummy(-1), *node = &dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                node = node->next = l1;
                l1 = l1->next;
            } else {
                node = node->next = l2;
                l2 = l2->next;
            }
        }
        if (l1) node->next = l1;
        if (l2) node->next = l2;

        return dummy.next;
    }
};
