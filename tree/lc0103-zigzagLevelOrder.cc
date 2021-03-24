class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) return res;

        queue<TreeNode*> myque;
        myque.push(root);
        bool forward = true;
        while (!myque.empty()) {
            int size = myque.size();
            vector<int> levelVec(size);
            for (int i = 0; i < size; i++) {
                TreeNode* node = myque.front();
                myque.pop();
                int idx = forward ? i : size-i-1;
                levelVec[idx] = node->val;
                if (node->left) myque.push(node->left);
                if (node->right) myque.push(node->right);
            }
            res.push_back(levelVec);
            forward = !forward;
        }

        return res;
    }
};
