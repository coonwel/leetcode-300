class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return height(root) >= 0;
    }

    int height(TreeNode* root) {
        if (root == nullptr) return 0; // 终止条件
        
        int left = height(root->left);
        int right = height(root->right);

        if (left < 0 || right < 0 || std::abs(left - right) > 1) return -1; // 剪枝

        return 1 + std::max(left, right); // 合并结果
    }
};
