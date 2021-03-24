class Solution {
public:
    int minDepth(TreeNode* root) {
        return minDepth(root, false);
    }

    int minDepth(TreeNode* root, bool hasbrother) {
        if (root == nullptr) return hasbrother ? INT_MAX : 0;

        return 1 + std::min(minDepth(root->left, root->right != nullptr),
                            minDepth(root->right, root->left != nullptr));
    }
};
