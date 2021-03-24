class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> res(k, nullptr);
        int len = 1;
        ListNode* node = head;
        while (node = node->next) {
            ++len;
        }

        int avg = (len / k), extra = (len % k);
        for (int i = 0; i < k && head != nullptr; ++i) {
            res[i] = head;
            for (int j = 1; j < avg + (i < extra); ++j) {
                head = head->next;
            }
            ListNode *tmp = head->next;
            head->next = NULL;
            head = tmp;
        }
        return res;
    }
};
