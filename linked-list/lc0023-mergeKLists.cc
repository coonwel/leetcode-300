
class Solution {
public:
    // 时间复杂度最优解为N * logK
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp=[](ListNode* l1, ListNode* l2) { return l1->val > l2->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> myque(cmp);

        for (auto l : lists) {
            if (l) myque.push(l);
        }

        ListNode dummy(-1), *node = &dummy;
        while (!myque.empty()) {
            node = node->next = myque.top();
            myque.pop();
            if (node->next) {
                myque.push(node->next);
            }
        }
        return dummy.next;
    }

    // 时间复杂度为 N * (K^2). 最优解为N * logK
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        ListNode* pNode = list[0];
        for (int i = 1; i < list.size(); i++) {
            if (lists[i] == nullptr) continue;
            pNode = mergeTwoLists(pNode, lists[i]);
        }
        return pNode;
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;

        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

