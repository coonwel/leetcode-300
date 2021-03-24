class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(-1), *node = &dummy;
        int carry = 0;
        while (l1 || l2 || carry > 0) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            node = node->next = new ListNode(sum%10);
            carry = sum / 10;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        return dummy.next;
    }
};
