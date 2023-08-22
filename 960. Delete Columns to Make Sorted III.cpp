class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int n = A.size();
        int m = A[0].size();
        
        vector<int> dp(m, 1); // Initialize with 1 as a single column is sorted
        
        for (int i = m - 2; i >= 0; --i) {
            for (int j = i + 1; j < m; ++j) {
                bool valid = true;
                for (int k = 0; k < n; ++k) {
                    if (A[k][i] > A[k][j]) {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }
        
        return m - *max_element(dp.begin(), dp.end());
    }
};
