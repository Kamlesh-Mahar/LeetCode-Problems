class Solution {
public:
    int countOrders(int n) {
        const int MOD = 1e9 + 7;
        long long ans = 1;
        
        for (int i = 1; i <= n; ++i) {
            long long ways = (2 * i - 1) * i;
            ans = (ans * ways) % MOD;
        }
        
        return ans;
    }
};
