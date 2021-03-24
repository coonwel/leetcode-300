class Solution {
public:
    ListNode* reverse(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode *prev = nullptr, *cur = head;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }

    // 反转版本
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return ;

        ListNode *slow = head, *fast = head, *prev = nullptr;
        while (fast && fast->next) {
            prev = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        prev->next = nullptr; // cur at middle

        slow = reverse(slow);

        ListNode *cur = head;
        while (cur->next) {
            ListNode* next = cur->next;
            cur->next = slow;
            slow = slow->next;
            cur->next->next = next;
            cur = next;
        }
        cur->next = slow;
    }


    // stack版本
    void reorderListII(ListNode* head) {
        stack<ListNode*> mystack;
        ListNode *cur = head;
        while (cur != nullptr) {
            mystack.push(cur);
            cur = cur->next;
        }
        cur = head;
        int count = (mystack.size()-1)/2;
        while (count--) {
            ListNode* node = mystack.top();
            mystack.pop();
            ListNode* next = cur->next;
            cur->next = node;
            node->next = next;
            cur = next;
        }
        mystack.top()->next = nullptr;
    }
};

