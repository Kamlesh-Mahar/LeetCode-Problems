class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (n < d) return -1;

        vector<std::vector<int>> dp(d + 1, vector<int>(n + 1, INT_MAX));
        dp[0][0] = 0;

        for (int i = 1; i <= d; ++i) {
            for (int j = i; j <= n; ++j) {
                int maxDifficulty = 0;
                for (int k = j - 1; k >= i - 1; --k) {
                    maxDifficulty = max(maxDifficulty, jobDifficulty[k]);
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + maxDifficulty);
                }
            }
        }

        return dp[d][n] == INT_MAX ? -1 : dp[d][n];
    }
};
