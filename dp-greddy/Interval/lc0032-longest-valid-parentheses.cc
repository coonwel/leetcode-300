class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int dp[n];
        std::fill(dp, dp+n, 0);
        int res = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] == ')') {
                int j = i - dp[i-1] - 1;
                if (j >= 0 && s[j] == '(') {
                    dp[i] = (i-j+1) + (j > 0 ? dp[j-1] : 0);
                    res = std::max(res, dp[i]);
                }
            }
        }
        return res;
    }
};
