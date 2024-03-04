class Solution {
public:
    int bagOfTokensScore(std::vector<int>& tokens, int P) {
        sort(tokens.begin(), tokens.end());
        int maxPoints = 0, points = 0;
        int left = 0, right = tokens.size() - 1;

        while (left <= right) {
            if (P >= tokens[left]) {
                P -= tokens[left++];
                points++;
                maxPoints = max(maxPoints, points);
            } else if (points > 0) {
                P += tokens[right--];
                points--;
            } else {
                break;
            }
        }

        return maxPoints;
    }
};
