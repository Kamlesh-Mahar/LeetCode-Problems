class Solution {
public:
    int countHomogenous(string s) {
        const int MOD = 1e9 + 7;
        long long count = 0;
        int currentLength = 1;

        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) {
                currentLength++;
            } else {
                count = (count + (1LL * currentLength * (currentLength + 1) / 2) % MOD) % MOD;
                currentLength = 1;
            }
        }
        count = (count + (1LL * currentLength * (currentLength + 1) / 2) % MOD) % MOD;

        return static_cast<int>(count);
    }
};

