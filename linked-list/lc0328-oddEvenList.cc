class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head==nullptr || head->next==nullptr)
            return head;

        ListNode *odd = head, *even = head->next, *evenHead = even;
        while (even && even->next) {
            odd  = odd->next = even->next;
            even = even->next = odd->next;
        }
        odd->next = evenHead;

        return head;
    }
};
