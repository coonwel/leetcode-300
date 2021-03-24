
RandomListNode* copyRandomList(RandomListNode* head) {
    RandomListNode* cur = head;
    while (cur) {
        RandomListNode* node = new RandomListNode(cur->label);
        node->next = cur->next;
        cur->next = node;
        cur = node->next;
    }

    cur = head;
    while (cur) {
        if (cur->random != nullptr) cur->next->random = cur->random->next;
        cur = cur->next->next;
    }

    cur = head;
    RandomListNode dummy(-1), *newcur = &dummy;
    while (cur) {
        newcur->next = cur->next;
        newcur = newcur->next;
        cur->next = cur->next->next;
        cur = cur->next;
    }
    return dummy.next;
}
