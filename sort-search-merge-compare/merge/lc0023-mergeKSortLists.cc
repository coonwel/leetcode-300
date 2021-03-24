
ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.size() == 0) return nullptr;

    ListNode* pNode = lists[0];
    for (int i = 1; i < lists.size(); i++) {
        pNode = mergeTwoLists(pNode, lists[i]);
    }
    return pNode;
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr) return l2;
    if (l2 == nullptr) return l1;
    if (l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

