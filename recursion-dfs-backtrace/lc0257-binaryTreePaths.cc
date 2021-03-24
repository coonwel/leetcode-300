class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string out;
        backtrace(root, out, res);
        return res;
    }

    void backtrace(TreeNode* root, string out, vector<string>& res) {
        if (root == nullptr) return;
        
        out += to_string(root->val);     
        if (!root->left && !root->right) {
            res.push_back(out);
            return;
        }

        if (root->left) backtrace(root->left, out+"->", res);
        if (root->right) backtrace(root->right, out+"->", res);
        out.pop_back();
    }
};
