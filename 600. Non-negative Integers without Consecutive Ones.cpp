class Solution {
public:
    int findIntegers(int n) {
        vector<int> dp(31);
        dp[0] = 1;
        dp[1] = 2;
        
        for (int i = 2; i < 31; ++i)
            dp[i] = dp[i - 1] + dp[i - 2];
        
        int i = 29, sum = 0, prev_bit = 0;
        while (i >= 0) {
            int bit = (n >> i) & 1;
            if (bit == 1) {
                sum += dp[i];
                if (prev_bit == 1)
                    return sum;
            }
            prev_bit = bit;
            --i;
        }
        
        return sum + 1;
    }
};
