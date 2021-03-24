ss Solution {
public:
    int res;
    int maxPathSum(TreeNode* root) {
        res = root->val;
        backtrace(root);
        return res;
    }

    int backtrace(TreeNode* root) {
        if (root == nullptr) return 0;

        int left = std::max(0, backtrace(root->left));
        int right = std::max(0, backtrace(root->right));

        res = std::max(root->val + left + right, res);

        return root->val + std::max(0, std::max(left, right));
    }
};
