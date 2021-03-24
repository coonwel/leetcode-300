class Solution {
public:
    // 递归方式
    bool isSameTreee(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true; // 终止条件
        if (!p || !q) return false; // 剪枝
        return p->val == q->val 
                && isSameTreee(p->left, q->left) 
                && isSameTreee(p->right, q->right);
    }

    // 迭代方式
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;

        TreeNode *node1 = p, *node2 = q;
        stack<TreeNode*> mystack1, mystack2;
        while (node1 || !mystack1.empty()) {
            if (node1 && node2) {
                if (node1->val != node2->val) return false;

                mystack1.push(node1);
                node1 = node1->left;

                mystack2.push(node2);
                node2 = node2->left;
            } else if (!node1 && !node2 && !mystack1.empty() && !mystack2.empty()) {
                node1 = mystack1.top();
                mystack1.pop();
                node1 = node1->right;

                node2 = mystack2.top();
                mystack2.pop();
                node2 = node2->right;
            } else {
                return false;
            }
        }
        return true;
    }
};
