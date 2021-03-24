class Solution {
public:
    ListNode* insertSortList(ListNode* head) {
        ListNode dummy(-1);
        dummy.next = head;

        while (head) {
            TreeNode* cur = &dummy;
            while (cur->next != nullptr && cur->next->val <= head->val) {
                cur = cur->next;
            }

            TreeNode* next = head->next;
            head->next = cur->next;
            cur->next = head;
            head = next;
        }

        return dummy.next;
    }
};
