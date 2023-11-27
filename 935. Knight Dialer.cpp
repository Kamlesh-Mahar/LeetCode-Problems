class Solution {
public:
    int knightDialer(int N) {
    const int MOD = 1e9 + 7;
    std::vector<std::vector<int>> moves = {
        {4, 6},
        {6, 8},
        {7, 9},
        {4, 8},
        {0, 3, 9},
        {},
        {0, 1, 7},
        {2, 6},
        {1, 3},
        {2, 4}
    };

    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(10, 0));

    for (int i = 0; i < 10; ++i) {
        dp[1][i] = 1;
    }

    for (int n = 2; n <= N; ++n) {
        for (int i = 0; i < 10; ++i) {
            for (int move : moves[i]) {
                dp[n][i] = (dp[n][i] + dp[n - 1][move]) % MOD;
            }
        }
    }

    int result = 0;
    for (int i = 0; i < 10; ++i) {
        result = (result + dp[N][i]) % MOD;
    }

    return result;
}
};
