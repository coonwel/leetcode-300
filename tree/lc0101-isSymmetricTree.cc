class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isSymmetric(root, root);
    }

    bool isSymmetric(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true; // 终止条件
        if (!p || !q) return false; // 剪枝
        return p->val == q->val
                && isSymmetric(p->left, q->right)
                && isSymmetric(p->right, q->left);
    }
};

