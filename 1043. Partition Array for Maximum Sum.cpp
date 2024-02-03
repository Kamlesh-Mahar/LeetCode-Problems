class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, 0);

        for (int i = 0; i < n; ++i) {
            int maxVal = arr[i];
            for (int j = 1; j <= k && i - j + 1 >= 0; ++j) {
                maxVal = max(maxVal, arr[i - j + 1]);
                dp[i] = max(dp[i], (i >= j ? dp[i - j] : 0) + maxVal * j);
            }
        }

        return dp[n - 1];
    }
};
