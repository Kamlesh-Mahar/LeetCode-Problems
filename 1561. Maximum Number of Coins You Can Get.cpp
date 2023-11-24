class Solution {
public:
    int maxCoins(std::vector<int>& piles) {
    int n = piles.size();
    int result = 0;

    sort(piles.begin(), piles.end());

    int rounds = n / 3;

    for (int i = n - 2; i >= rounds; i -= 2) {
        result += piles[i];
    }

    return result;
}
};
