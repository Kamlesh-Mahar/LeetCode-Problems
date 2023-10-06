class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);

        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i / 2; ++j) {
                int product = max(j, dp[j]) * max(i - j, dp[i - j]);
                dp[i] = max(dp[i], product);
            }
        }

        return dp[n];
    }
};
