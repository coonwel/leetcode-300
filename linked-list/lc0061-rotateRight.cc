class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || k < 1) return 0;

        int len = 1;
        ListNode* node = head;
        while (node = node->next)
            len++;
        node->next = head; // 首尾相连

        k = len - k%len;
        for (int step = 0; step < k; step++)
            node = node->next;
        head = node->next;
        node->next = nullptr; // 断开环
        return head;
    }
};
