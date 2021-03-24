
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode dummy(-1);
        while (head) {
            ListNode *cursor = &dummy;
            while (cursor->next && cursor->next->val <= head->val) {
                cursor = cursor->next;
            }

            ListNode *next = head->next;
            head->next = cursor->next;
            cursor->next = head;
            head = next;
        }
        return dummy.next;
    }
};


