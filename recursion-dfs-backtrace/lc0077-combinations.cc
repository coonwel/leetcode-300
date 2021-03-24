class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> out;
        backtrace(n, k, 1, out, res);
        return res;
    }

    void backtrace(int n, int k, int start, vector<int>& out, vector<vector<int>>& res) {
        if (k == out.size()) {
            res.push_back(out);
        } else {
            for (int i = start; i <= n; i++) {
                out.push_back(i);
                backtrace(n, k, i+1, out, res);
                out.pop_back();
            }
        }
    }
};
