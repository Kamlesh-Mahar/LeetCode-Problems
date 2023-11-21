class Solution {
public:
    const int MOD = 1e9 + 7;

int countNicePairs(std::vector<int>& nums) {
    unordered_map<int, int> frequency;
    long long nicePairsCount = 0;

    for (int num : nums) {
        int reversed = 0;
        int n = num;

        while (n > 0) {
            reversed = reversed * 10 + n % 10;
            n /= 10;
        }

        int diff = num - reversed;
        nicePairsCount = (nicePairsCount + frequency[diff]) % MOD;
        frequency[diff]++;
    }

    return static_cast<int>(nicePairsCount);
}
};
