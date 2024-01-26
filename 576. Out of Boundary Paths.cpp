class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startCol) {
        const int MOD = 1e9 + 7;
        vector<vector<vector<int>>> dp(maxMove + 1,vector<vector<int>>(m, vector<int>(n, 0)));

        for (int move = 1; move <= maxMove; ++move) {
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    long long paths = 0;
                    paths = (paths + (i == 0 ? 1 : dp[move - 1][i - 1][j])) % MOD;
                    paths = (paths + (i == m - 1 ? 1 : dp[move - 1][i + 1][j])) % MOD;
                    paths = (paths + (j == 0 ? 1 : dp[move - 1][i][j - 1])) % MOD;
                    paths = (paths + (j == n - 1 ? 1 : dp[move - 1][i][j + 1])) % MOD;

                    dp[move][i][j] = paths;
                }
            }
        }

        return dp[maxMove][startRow][startCol];
    }
};
