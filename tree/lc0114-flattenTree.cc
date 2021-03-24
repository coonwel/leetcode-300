class Solution {
public:
    // 迭代方式
    void flatten(TreeNode* root) {
        if (nullptr == root) return;

        TreeNode* cur = root;
        while (cur) {
            if (nullptr != cur->left) {
                TreeNode* rightMost = cur->left;
                while (nullptr != rightMost->right)
                    rightMost = rightMost->right;
                rightMost->right = cur->right;
                cur->right = cur->left;
                cur->left = nullptr;
            }
            cur = cur->right;
        }
    }

    // 递归方式
    TreeNode* last = nullptr;
    void flatten(TreeNode* root) {
        if (nullptr == root) return;
        flatten(root->right);
        flatten(root->left);
        root->right = last;
        root->left = nullptr;
        last = root;
    }
};
