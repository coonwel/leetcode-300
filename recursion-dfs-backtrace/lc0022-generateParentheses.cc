class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string out;
        backtrace(n, n, out, res);
        return res;
    }

    void backtrace(string s, int left, int right, vector<string>& res) {
        if (left < 0 || right < 0 || left > right) return; // 剪枝

        if (left == 0 && right == 0) {
            res.push_back(s);
            return ;
        }

        backtrace(out + "(", left - 1, right, res);
        backtrace(out + ")", left, right - 1, res);
    }
};
