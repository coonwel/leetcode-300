class Solution {
public:
    TreeNode* sortArrayToBST(vector<int>& nums) {
        return dfs(nums, 0, nums.size()-1);
    }

    TreeNode* dfs(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;

        int mid = left + (right - left)/2;

        TreeNode* root = new TreeNode(nums[mid]);
        if (mid > left) root->left = dfs(nums, left, mid-1);
        if (mid < right) root->right = dfs(nums, mid+1, right);

        return root;
    }
};
