class Solution {
public:
    int backPackII(int m, vector<int> &nums, vector<int> &values) {
        int n = nums.size();
        int dp[n+1][m+1];
        std::fill_n(&dp[0][0], (n+1)*(m+1), 0);
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (j < nums[i-1])
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = std::max(dp[i-1][j], values[i-1] + dp[i-1][j - nums[i-1]]);
            }
        }
        
        return dp[n][m];
    }

    int backPackII(int m, vector<int> &nums, vector<int> &values) {
        int n = A.size();
        int dp[m+1];
        std::fill_n(&dp[0], m+1, 0);
        
        for (int i = 0; i < n; i++) {
            for (int j = m; j >= nums[i]; j--) {
                dp[j] = std::max(dp[j], values[i] + dp[j - nums[i]]);
            }
        }
        
        return dp[m];
    }
};
