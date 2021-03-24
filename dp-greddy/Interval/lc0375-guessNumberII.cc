class Solution {
public:
    int getMoneyAmount(int n) {
        int dp[n+1][n+1];
        std::fill_n(&dp[0][0], (n+1)*(n+1), 0);
        for (int i = 1; i <= n; i++) {
            for (int j = i-1; j >= 1; j--) {
                int globalMin = INT_MAX;
                for (int k = j; k < i; k++) {
                    int localMin = k + std::max(dp[j][k-1], dp[k+1][i]);
                    globalMin = std::min(globalMin, localMin);
                }
                dp[j][i] = globalMin;
            }
        }
        return dp[1][n];
    }
};
