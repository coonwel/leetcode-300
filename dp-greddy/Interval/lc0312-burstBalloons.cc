class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);

        int n = nums.size();
        int dp[n][n];
        std::fill_n(&dp[0][0], n*n, 0);
        for (int i = n-1; i >= 0; i--) {
            for (int j = i+1; j <= n-1; j++) {
                for (int k = i+1; k < j; k++) {
                    dp[i][j] = std::max(
                            dp[i][j],
                            dp[i][k] + dp[k][j] + nums[i] * nums[k] * nums[j]
                        );
                }
            }
        }

        return dp[0][n-1];
    }
};
