class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        vector<int> suffixSum(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int M = 1; M <= n; M++) {
                for (int X = 1; X <= 2 * M && i + X <= n; X++) {
                    int take = suffixSum[i] - suffixSum[i + X];
                    dp[i][M] = max(dp[i][M], take + suffixSum[i + X] - dp[i + X][max(M, X)]);
                }
            }
        }

        return dp[0][1];
    }
};
