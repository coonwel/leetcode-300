class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) return nullptr;
        return dfs(head, nullptr);
    }

    TreeNode* dfs(ListNode* head, ListNode* tail) {
        if (head == tail) return nullptr;

        ListNode *slow = head, *fast = head;
        while (fast != tail && fast->next != tail) {
            slow = slow->next;
            fast = fast->next->next;
        }

        TreeNode *root = new TreeNode(slow->val);
        root->left = dfs(head, slow);
        root->right = dfs(slow->next, tail);

        return root;
    }
};
