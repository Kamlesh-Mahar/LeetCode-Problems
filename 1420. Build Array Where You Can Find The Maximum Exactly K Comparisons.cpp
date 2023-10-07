class Solution {
 public:
  int numOfArrays(int n, int m, int k) {
    constexpr int kMod = 1'000'000'007;
    vector<vector<vector<int>>> dp(
        n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1)));

    for (int j = 1; j <= m; ++j)
      dp[1][j][1] = 1;

    for (int i = 2; i <= n; ++i)                
      for (int j = 1; j <= m; ++j)               
        for (int cost = 1; cost <= k; ++cost) {  
          dp[i][j][cost] = static_cast<long>(j) * dp[i - 1][j][cost] % kMod;
          for (int prevMax = 1; prevMax < j; ++prevMax) {
            dp[i][j][cost] += dp[i - 1][prevMax][cost - 1];
            dp[i][j][cost] %= kMod;
          }
        }

    int ans = 0;
    for (int j = 1; j <= m; ++j) {
      ans += dp[n][j][k];
      ans %= kMod;
    }
    return ans;
  }
};
