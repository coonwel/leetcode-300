class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode *fast = head, *slow = head, *prev;
        while (fast && fast->next) {
            prev = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        prev->next = nullptr;

        return mergeTwoList(sortList(head), sortList(slow));
    }

    ListNode* mergeTwoList(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;

        if (l1->val < l2->val) {
            l1->next = mergeTwoList(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoList(l1, l2->next);
            return l2;
        }
    }
};
