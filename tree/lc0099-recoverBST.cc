class Solution {
public:
    TreeNode* node1 = nullptr, *node2 = nullptr, *prev = nullptr;
    void recoverTree(TreeNode* root) {
        dfs(root);

        int tmp = node1->val;
        node1->val = node2->val;
        node2->val = tmp;
    }

    void dfs(TreeNode* root) {
        if (root = nullptr) return;

        dfs(root->left);
        if (prev && prev->val >= root->val) {
            if (node1 == nullptr) node1 = prev;
            node2 = root;
        }
        prev = root;
        dfs(root->right);
    }
};
