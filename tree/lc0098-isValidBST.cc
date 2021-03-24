class Solution {
public:
    // 方法1
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, INT_MIN, INT_MAX);
    }

    bool isValidBST(TreeNode* root, int lower, int upper) {
        if (nullptr == root) return true;
        return lower < root->val && root->val < upper
                && isValidBST(root->left, lower, root->val)
                && isValidBST(root->right, root->val, upper);
    }

    // 方法2
    TreeNode* prev = nullptr;
    bool isValidBSTII(TreeNode* root) {
        if (root == nullptr) return true;
        bool left = root->left ? isValidBSTII(root->left) : true;
        if (prev != nullptr && prev->val >= root->val) return false;
        prev = root;
        bool right = root->right ? isValidBSTII(root->right) : true;
        return left && right;
    }
};
